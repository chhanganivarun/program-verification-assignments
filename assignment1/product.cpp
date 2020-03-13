#include <cstdio>
#include <assert.h>
#include <iostream>
using namespace std;
#include "vops.h"
#include "product.h"
namespace ANONYMOUS{

void multTest__Wrapper() {
  multTest();
}
void multTest__WrapperNospec() {}
void multTest() {
  bool _tt0[3] = {0, 0, 0};
  int*  __sa18= new int [2 * 3]; CopyArr<int >(__sa18,_tt0, 2 * 3, 3);
  int _tt1[2] = {1, 2};
  CopyArr<int >((__sa18+ 0),_tt1, 2, 2);
  int _tt2[2] = {1, 5};
  CopyArr<int >((__sa18+ 2),_tt2, 2, 2);
  int _tt3[2] = {3, 4};
  CopyArr<int >((__sa18+ 4),_tt3, 2, 2);
  bool _tt4[2] = {0, 0};
  int*  __sa19= new int [3 * 2]; CopyArr<int >(__sa19,_tt4, 3 * 2, 2);
  int _tt5[3] = {1, 2, 3};
  CopyArr<int >((__sa19+ 0),_tt5, 3, 3);
  int _tt6[3] = {0, 2, 1};
  CopyArr<int >((__sa19+ 3),_tt6, 3, 3);
  bool _tt7[3] = {0, 0, 0};
  int*  _out_s15= new int [3 * 3]; CopyArr<int >(_out_s15,_tt7, 3 * 3, 3);
  product(3, 2, 2, 3, __sa18, __sa19, _out_s15);
  bool _tt8[3] = {0, 0, 0};
  int*  __sa20= new int [3 * 3]; CopyArr<int >(__sa20,_tt8, 3 * 3, 3);
  int _tt9[3] = {1, 6, 5};
  CopyArr<int >((__sa20+ 0),_tt9, 3, 3);
  int _tt10[3] = {1, 12, 8};
  CopyArr<int >((__sa20+ 3),_tt10, 3, 3);
  int _tt11[3] = {3, 14, 13};
  CopyArr<int >((__sa20+ 6),_tt11, 3, 3);
  assert (arrCompare(_out_s15, (3 * 3), __sa20, (3 * 3)) && (((3) == (3)) && ((3) == (3))));;
  bool _tt12[3] = {0, 0, 0};
  int*  __sa21= new int [2 * 3]; CopyArr<int >(__sa21,_tt12, 2 * 3, 3);
  int _tt13[2] = {1, 2};
  CopyArr<int >((__sa21+ 0),_tt13, 2, 2);
  int _tt14[2] = {1, 5};
  CopyArr<int >((__sa21+ 2),_tt14, 2, 2);
  int _tt15[2] = {3, 4};
  CopyArr<int >((__sa21+ 4),_tt15, 2, 2);
  bool _tt16[2] = {0, 0};
  int*  __sa22= new int [3 * 2]; CopyArr<int >(__sa22,_tt16, 3 * 2, 2);
  int _tt17[3] = {1, 2, 3};
  CopyArr<int >((__sa22+ 0),_tt17, 3, 3);
  int _tt18[3] = {0, 2, 1};
  CopyArr<int >((__sa22+ 3),_tt18, 3, 3);
  bool _tt19[3] = {0, 0, 0};
  int*  _out_s17= new int [3 * 3]; CopyArr<int >(_out_s17,_tt19, 3 * 3, 3);
  productSK(3, 2, 2, 3, __sa21, __sa22, _out_s17);
  bool _tt20[3] = {0, 0, 0};
  int*  __sa23= new int [3 * 3]; CopyArr<int >(__sa23,_tt20, 3 * 3, 3);
  int _tt21[3] = {1, 6, 5};
  CopyArr<int >((__sa23+ 0),_tt21, 3, 3);
  int _tt22[3] = {1, 12, 8};
  CopyArr<int >((__sa23+ 3),_tt22, 3, 3);
  int _tt23[3] = {3, 14, 13};
  CopyArr<int >((__sa23+ 6),_tt23, 3, 3);
  assert (arrCompare(_out_s17, (3 * 3), __sa23, (3 * 3)) && (((3) == (3)) && ((3) == (3))));;
  delete[] __sa18;
  delete[] __sa19;
  delete[] _out_s15;
  delete[] __sa20;
  delete[] __sa21;
  delete[] __sa22;
  delete[] _out_s17;
  delete[] __sa23;
}
void product(int M, int N, int P, int Q, int* a/* len = N * M */, int* b/* len = Q * P */, int* _out/* len = Q * M */) {
  for (int  __sa25=0;(__sa25) < (M);__sa25 = __sa25 + 1){
    assert (((__sa25) >= (0)) && ((__sa25) < (M)));;
    CopyArr<int >((_out+ Q * __sa25),0, Q);
  }
  assert ((P) == (N));;
  int  sum=0;
  for (int  i=0;(i) < (M);i = i + 1){
    for (int  j=0;(j) < (Q);j = j + 1){
      sum = 0;
      for (int  k=0;(k) < (P);k = k + 1){
        assert (((i) >= (0)) && ((i) < (M)));;
        assert (((k) >= (0)) && ((k) < (N)));;
        assert (((k) >= (0)) && ((k) < (P)));;
        assert (((j) >= (0)) && ((j) < (Q)));;
        sum = sum + ((a[((N * i) + k)]) * (b[((Q * k) + j)]));
      }
      assert (((i) >= (0)) && ((i) < (M)));;
      assert (((j) >= (0)) && ((j) < (Q)));;
      (_out[(Q * i) + j]) = sum;
    }
  }
  return;
}
void productSK(int M, int N, int P, int Q, int* a/* len = N * M */, int* b/* len = Q * P */, int* _out/* len = Q * M */) {
  for (int  __sa24=0;(__sa24) < (M);__sa24 = __sa24 + 1){
    assert (((__sa24) >= (0)) && ((__sa24) < (M)));;
    CopyArr<int >((_out+ Q * __sa24),0, Q);
  }
  bool  __sa0=(0) < (Q);
  int  sum=0;
  int  i=0;
  while (__sa0) {
    bool  __sa1=(0) < (Q);
    int  j=0;
    while (__sa1) {
      sum = 0;
      bool  __sa2=(0) < (P);
      int  k=0;
      while (__sa2) {
        assert (((i) >= (0)) && ((i) < (M)));;
        assert (((k) >= (0)) && ((k) < (N)));;
        assert (((k) >= (0)) && ((k) < (P)));;
        assert (((j) >= (0)) && ((j) < (Q)));;
        sum = sum + ((a[((N * i) + k)]) * (b[((Q * k) + j)]));
        k = k + 1;
        __sa2 = (k) < (P);
      }
      assert (((i) >= (0)) && ((i) < (M)));;
      assert (((j) >= (0)) && ((j) < (Q)));;
      (_out[(Q * i) + j]) = sum;
      j = j + 1;
      __sa1 = (j) < (Q);
    }
    i = i + 1;
    __sa0 = (i) < (Q);
  }
  return;
}

}
