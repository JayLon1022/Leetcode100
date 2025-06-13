//
// Created by JayLon on 2025/6/13.双向链表
//
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DoublyLinkedListNode{
  public:
    int val;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;
    DoublyLinkedListNode(int x): val(x), next(NULL), prev(NULL) {}
};

DoublyLinkedListNode* createDoublyLinkedList(const vector<int>& arr){
  if(arr.empty()){
    return nullptr;
  }
  DoublyLinkedListNode* head = new DoublyLinkedListNode(arr[0]);
  DoublyLinkedListNode* cur = head;
  for(int i = 1; i < arr.size(); i++){
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(arr[i]);
    cur->next = newNode;
    newNode->prev = cur;
    cur = cur->next;
  }
  return head;
}

int main(){
  DoublyLinkedListNode* head = createDoublyLinkedList({1,2,3,4,5});
  DoublyLinkedListNode* tail = nullptr;

//  从头查
  for(DoublyLinkedListNode* p = head; p!=nullptr; p = p->next){
    cout << p->val << endl;
    tail = p;
  }

//  从尾查
  for(DoublyLinkedListNode* p = tail; p!=nullptr; p = p->prev){
    cout << p->val << endl;
  }

//  头插
  DoublyLinkedListNode* newHead = new DoublyLinkedListNode(0);
  newHead->next = head;
  head->prev = newHead;
  head = newHead;

//  尾插
  tail = head;
  while(tail->next!=nullptr){
    tail = tail->next;
  }
  DoublyLinkedListNode* newNode = new DoublyLinkedListNode(0);
  tail->next = newNode;
  newNode->prev = tail;
  tail = newNode;

//  中插
  DoublyLinkedListNode *p = head;
  for(int i = 0; i < 2; i++){
    p = p->next;
  }
  newNode = new DoublyLinkedListNode(66);
  newNode->next = p->next;
  newNode->prev = p;
  p->next->prev = newNode;
  p->next = newNode;

//  中删
  p = head;
  for(int i = 0; i < 3; i++){
    p = p->next;
  }
  DoublyLinkedListNode* toDelete = p->next;
  p->next = toDelete->next;
  toDelete->next->prev = p;
  toDelete->next = nullptr;
  toDelete->prev = nullptr;

//  头删
  toDelete = head;
  head = head->next;
  head->prev = nullptr;
  toDelete->prev = nullptr;

//  尾删
  p = head;
  while(p != nullptr){
    p = p->next;
  }
  toDelete = p;
  p = p->prev;
  p->next = nullptr;
  toDelete->prev = nullptr;

  return 0;
}