datatype StateSpace = StateSpace(i: int,a: int, b: int, n:int)
function method fibb(n: int): int
decreases n
requires n>=0
{
if n <= 0 then 0 else if n == 1 then 1 else fibb(n-1)+fibb(n-2)
}

method FibonacciTransitions(initialState: StateSpace) returns (finalState: StateSpace)
decreases initialState.i
requires initialState.n>=0
requires initialState.i >=0
// requires initialState.n>=2 ==> initialState.a == fibb(initialState.n - initialState.i+1)
// requires initialState.n>=2==> initialState.b == fibb(initialState.n - initialState.i)
// ensures initialState.n>=2 ==> finalState.a == fibb(initialState.n - initialState.i+2)
// ensures initialState.n>=2 ==> finalState.b == fibb(initialState.n - initialState.i+1)
{
    if initialState.n == 0{
        return StateSpace(0,0,0,initialState.n);
    }
    else if initialState.i <= 2 {
        // print "\ntest2\n";
        // print initialState;

        return StateSpace(0,initialState.a+initialState.b,initialState.a,initialState.n);
    }
    else{
        // print "\ntest\n";
        // print initialState;
        var s:= FibonacciTransitions(StateSpace(initialState.i-1,initialState.a+initialState.b,initialState.a,initialState.n));
        return s;
    } 
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
// print c;
// print '\n';
// print fibb(n);
// assert c == fibb(n);
}