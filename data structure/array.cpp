//
// Created by JayLon on 2025/6/13.动态数组
//
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
vector<int> arr;
int main(){

//  定义数组
  for(int i=0; i<arr.size(); i++){
    arr.push_back(i);
  }

//  插值
  arr.insert(arr.begin()+2, 0);
  arr.insert(arr.begin(),-1);

//  删值
  arr.pop_back();//末尾
  arr.erase(arr.begin()+2);//删除对应索引

//  根据索引查询元素
  int a = arr[0];
  arr[0] = 0;

//  根据元素查询索引
  int index = find(arr.begin(),arr.end(),0)-arr.begin();
  return 0;
}
