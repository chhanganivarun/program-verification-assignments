#include <cstdio>
#include <assert.h>
#include <iostream>
using namespace std;
#include "vops.h"
#include "linkedList.h"
namespace ANONYMOUS{

Node* Node::create(Node*  next_, int  val_){
  void* temp= malloc( sizeof(Node)  ); 
  Node* rv = new (temp)Node();
  rv->next =  next_;
  rv->val =  val_;
  return rv;
}
List* List::create(Node*  head_){
  void* temp= malloc( sizeof(List)  ); 
  List* rv = new (temp)List();
  rv->head =  head_;
  return rv;
}
void testInsert__Wrapper() {
  testInsert();
}
void testInsert__WrapperNospec() {}
void testAppend__Wrapper() {
  testAppend();
}
void testAppend__WrapperNospec() {}
void testInsert() {
  List*  l=List::create(NULL);
  List*  l_s23=NULL;
  populate(l, l_s23);
  Node*  n1=Node::create(NULL, 70);
  List*  l2_s25=NULL;
  insertAt(l_s23, n1, 1, l2_s25);
  assert ((l2_s25->head->next->val) == (70));;
}
void testAppend() {
  List*  l=List::create(NULL);
  List*  l_s27=NULL;
  populate(l, l_s27);
  Node*  n1=Node::create(NULL, 40);
  List*  l1_s29=NULL;
  append(l_s27, n1, l1_s29);
  assert ((l1_s29->head->next->next->val) == (40));;
}
void populate(List* l, List*& _out) {
  Node*  n2=Node::create(NULL, 60);
  Node*  n1=Node::create(n2, 5);
  l->head = n1;
  _out = l;
  return;
}
void insertAt(List* lst, Node* n, int pos, List*& _out) {
  Node*  nde=lst->head;
  Node*  next_nde=lst->head->next;
  bool  __sa1=(0) < ((pos - 1));
  while (__sa1) {
    nde = next_nde->next;
    next_nde = next_nde->next;
    __sa1 = (0) < (pos);
  }
  Node*  _tmprhs_s8=Node::create(NULL, n->val);
  nde->next = _tmprhs_s8;
  nde->next = n;
  _out = lst;
  return;
}
void append(List* lst, Node* n, List*& _out) {
  Node*  nde=lst->head;
  if ((nde) == (NULL)) {
    lst->head = n;
    _out = lst;
    return;
  }
  bool  __sa0=(nde->next) != (NULL);
  while (__sa0) {
    nde = nde->next;
    __sa0 = (nde->next) != (NULL);
  }
  Node*  _tmprhs_s19=Node::create(n, n->val);
  nde->next = _tmprhs_s19;
  _out = lst;
  return;
}

}
