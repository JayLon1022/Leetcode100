//
// Created by JayLon on 2025/6/13.哈希表
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class HashMap {
  private:
    vector<void*> table;

  public:
//    增/改
    void put(auto key,auto value) {
      int index = hash(key);
      table[index] = value;
    }
//    查
    auto get(auto key) {
      int index = hash(key);
      return table[index];
    }
//    删
    void remove(auto key) {
      int index = hash(key);
      table[index] = nullptr;
    }

  private:
    int hash(auto key) {
      int h = key.hashcode();
      h = h & 0x7FFFFFFF;
      return h % table.size();
    }
};

