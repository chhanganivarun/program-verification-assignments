datatype StateSpace = StateSpace(i: int,a: int, b: int)
function method fibb(n: int): int
decreases n
requires n>=0
{
if n <= 0 then 0 else if n == 1 then 1 else fibb(n-1)+fibb(n-2)
}

method FibonacciTransitions(initialState: StateSpace) returns (finalState: StateSpace)
// pre conditions
requires initialState.i >= 0
requires initialState.a == 0
//post condition
ensures finalState.i == 0
ensures finalState.a >= 1 ==> initialState.i >= 1
ensures initialState.i >= 1 ==> finalState.a >= 1
ensures initialState.i == 0 ==> finalState.a == 0
ensures initialState.i == 1 ==> finalState.a == 1
ensures initialState.i >=1 ==> finalState.b == fibb(initialState.i-1)
ensures finalState.a == fibb(initialState.i)
ensures finalState.a >= finalState.b
{
var n := initialState.i;
var i: int := n;
var a := 0;
var b := 1;
var c := a+b;

if i == 0 {
return StateSpace(0,0,0);
}
else if i == 1 {
return StateSpace(0,1,0);
}
else{
//n := n-2;
i := n-1;
while i >= 1
// loop invariance
decreases i
invariant 0 <= i <= n-1
invariant c == b
invariant c == fibb(n-i)
invariant a == fibb(n-i-1)
invariant b == fibb(n-i)
invariant c-a >= 0
{
c := a+b;
a := b;
b := c;
i := i-1;
}
return StateSpace(i,c,a);
}
}


function method rho(n: int): StateSpace
{
StateSpace(n,0,0)
}
function method pi(state: StateSpace): int
{
state.a
}

method Main()
{
var initialState := rho(6);
var terminalState := FibonacciTransitions(initialState);
var c:= pi(terminalState); 
assert c == fibb(6);
}