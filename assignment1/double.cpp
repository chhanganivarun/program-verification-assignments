#include <cstdio>
#include <assert.h>
#include <iostream>
using namespace std;
#include "vops.h"
#include "double.h"
namespace ANONYMOUS{

void doubleSketch__Wrapper(int x) {
  doubleSketch(x);
}
void doubleSketch__WrapperNospec(int x) {}
void doubleSketch(int x) {
  assert (((x * 2)) == ((x + x)));;
}

}
