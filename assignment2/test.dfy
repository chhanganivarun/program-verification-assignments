// State Space
datatype StateSpace
= StateSpace(i:int,a:int)
function fact(i:int): int
decreases i
{
if i >0 then i * fact(i-1) else 1
}
// Transition System
method FactorialTransitions(initialState: StateSpace) returns (finalState: StateSpace)
// pre conditions
requires initialState.i >= 0
requires initialState.a == 1
//post condition
ensures finalState.i == 0
ensures finalState.a >= 1 ==> initialState.a >= 1
ensures finalState.a == fact(initialState.i)
{
var n := initialState.i;
var i: int := n;
if i == 0 {
return StateSpace(0,1);
}
else{
var f := 1;
while i >= 1
// loop invariance
decreases i
invariant 0 <= i <= n
invariant fact(i)*f == fact(n)
{
f := f * i;
i := i - 1;
}
return StateSpace(i,f);
}
}
// Converts state space to output space
function method pi(state: StateSpace): int
{
state.a
}
// Converts input space to state space
function method rho(n:int) : StateSpace
{
StateSpace(n,1)
}
// Orchestrator
method Main(){
var initialState := rho(5);
var terminalState := FactorialTransitions(initialState);
var f := pi(terminalState);
assert f == 120;
}