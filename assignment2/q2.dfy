datatype StateSpace = StateSpace(i: int,a: int, b: int, n:int)
function method fibb(n: int): int
decreases n
requires n>=0
{
if n <= 0 then 0 else if n == 1 then 1 else fibb(n-1)+fibb(n-2)
}

function method FibonacciTransitions(initialState: StateSpace): StateSpace
decreases initialState.i
requires initialState.n>=0
requires initialState.i >=0
// requires initialState.a == fibb(initialState.n - initialState.i-1)
// requires initialState.b == fibb(initialState.n - initialState.i-0)
{
    if initialState.n == 0 then StateSpace(0,0,0,initialState.n)
    else if initialState.i <= 2 then StateSpace(0,initialState.a+initialState.b,initialState.a,initialState.n)
    else FibonacciTransitions(StateSpace(initialState.i-1,initialState.a+initialState.b,initialState.a,initialState.n))
}


function method rho(n: int): StateSpace
{
StateSpace(n,1,0,n)
}
function method pi(state: StateSpace): int
{
state.a
}

method Main()
{
    var n:=5;
var initialState := rho(n);
var terminalState := FibonacciTransitions(initialState);
var c:= pi(terminalState);
assert c == fibb(n);
}