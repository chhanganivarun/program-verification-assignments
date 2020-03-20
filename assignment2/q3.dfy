datatype StateSpace = StateSpace(arr: array<int>,sf: int)


predicate sorted(a: array<int>, l: int, u: int)
reads a
{
    forall i, j :: 0 <= l <= i <= j <= u < a.Length ==> a[i] <= a[j]
}

function method rho(arr: array<int>): StateSpace
{
    StateSpace(arr,arr.Length-1)
}

function method pi(state: StateSpace): array<int>
{
    state.arr
}

method SortTransitions(initialState: StateSpace) returns (finalState: StateSpace)
decreases initialState.sf
requires 0<=initialState.sf <=initialState.arr.Length-1
requires initialState.arr.Length >=2

requires sorted(initialState.arr,initialState.sf,initialState.arr.Length-1)

ensures sorted(finalState.arr,finalState.sf,finalState.arr.Length-1)
ensures finalState.sf < finalState.arr.Length-1
ensures finalState.sf+1 < finalState.arr.Length
ensures 0<=finalState.sf<=initialState.arr.Length-1
ensures initialState.sf == initialState.arr.Length-1 ==> finalState.sf<initialState.sf
// ensures finalState.arr[initialState.sf] <= initialState.arr[initialState.sf]
ensures initialState.sf <= finalState.arr.Length-1
ensures finalState.arr.Length == initialState.arr.Length
ensures finalState.sf<=initialState.sf<=finalState.arr.Length-1
{
    if initialState.sf<1
    {
        return initialState;
    }
    var a:=new int[initialState.arr.Length];
    var i:=0;
    while i<initialState.arr.Length
    decreases initialState.arr.Length -i
    invariant 0<=i<=initialState.arr.Length
    {
        a[i]  := initialState.arr[i];
        i:=i+1;
    }
    var sf := initialState.sf;
    while sf>0
    decreases sf
    invariant 0<=sf<=initialState.sf
    // invariant sorted(a,sf,a.Length-1)
    {
    i := 0;
    while i<sf
    decreases sf-i
    invariant 0<=i<=sf
    
    {
        if a[i] > a[i+1]
        {
            a[i],a[i+1] := a[i+1],a[i];
        }
        i:=i+1;
    }
    sf:=sf-1;
    }
    var s:= StateSpace(a,initialState.sf-1);
    return s;
}
method Main()
{
    var a := new int[5];
  a[0], a[1], a[2], a[3], a[4] := 9, 4, 6, 3, 8;
  var initialState:= rho(a);
  var terminalState := SortTransitions(initialState);
  var b:= pi(terminalState);
  var c:=new int[a.Length];
  c[0],c[1],c[2],c[3],c[4] := 3,4,6,8,9;
  var k := 0;
  
  while(k < a.Length) 
  decreases a.Length-k
  invariant 0<=k<=c.Length
  invariant 0<=k<=b.Length
  {
    print b[k], "\n"; k := k+1;
    // assert c[k] == b[k];
  }
  
}