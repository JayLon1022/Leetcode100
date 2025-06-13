//
// Created by JayLon on 2025/6/13.单链表
//
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//单链表
class ListNode{
  public:
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* createLinkedList(const vector<int> &arr){
  if(arr.empty()){
    return nullptr;
  }
  ListNode *head = new ListNode(arr[0]);
  ListNode *cur = head;
  for(int i = 1; i < arr.size(); i++){
    cur->next = new ListNode(arr[i]);
    cur = cur->next;
  }
  return head;
}

int main(){
  ListNode *head = createLinkedList({1,2,3,4,5,6,7,8,9});

//  遍历
  for(ListNode *p = head; p !=nullptr; p = p->next){
    cout<<p->val<<" "<<endl;
  }

//  插入新值
  //  头插
  ListNode *newNode = new ListNode(0);
  newNode->next = head;
  head = newNode;

  //  尾插
  ListNode *p = head;
  while(p->next != nullptr){
    p=p->next;
  }
  ListNode *newHead = new ListNode(10);
  p->next = newHead;

  //  中插
  ListNode *p2 = head;
  for(int i=0;i<2;i++){
    p2=p2->next;
  }
  ListNode *newNode2 = new ListNode(66);
  newNode2->next = p->next;
  p->next = newNode;

//  删除节点
  //  中删
  ListNode *p3 = head;
  for(int i=0;i<2;i++){
    p3=p3->next;
  }
  p3->next=p3->next->next;

  //  尾删
  ListNode *p4 =head;
  while(p4->next->next!=nullptr){
    p4=p4->next;
  }
  p4->next = nullptr;

  //  头删
  head = head->next;

  return 0;
}