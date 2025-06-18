//
// Created by JayLon on 2025/6/18.哈希链表
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename K, typename V>
struct Node {
  K key;
  V val;
  Node* next;
  Node* prev;

  Node(K key, V val): key(key), val(val), next(nullptr), prev(nullptr) {}
};

template <typename K, typename V>
class MyLinkedHashMap {
  public:
    MyLinkedHashMap() {
      head = new Node<K, V>(K(), V());
      tail = new Node<K, V>(K(), V());
      head->next = tail;
      tail->prev = head;
    }

    V get(K key) {
      //不存在
      if(map.find(key) == map.end()) {
        return V();
      }
      //存在
      return map[key]->val;
    }

    void put(K key, V val) {
      //不存在，同时插入链表和map
      if(map.find(key) == map.end()) {
        Node<K,V>* node = new Node<K,V>(key, val);
        addLastNode(node);
        map[key] = node;
        return;
      }
      //存在，直接替换
      map[key]->val = val;
    }

    void remove(K key) {
      //不存在
      if(map.find(key) == map.end()) {
        return;
      }
      //存在,同时删除链表和map中的节点
      Node<K,V>* node = map[key];
      map.erase(key);
      removeLastNode(node);
    }

    bool containsKey(K key){
      return map.find(key) != map.end();
    }

    vector<K> keys(){
      vector<K> keylist;
      for(Node<K,V>* p = head->next; p; p = p->next) {
        keylist.push_back(p->key);
      }
      return keylist;
    }


  private:

    Node<K,V>* head;
    Node<K,V>* tail;
    unordered_map<K, Node<K,V>*> map;

    void addLastNode(Node<K,V>* x) {
      Node<K,V>* temp = tail->prev;
      x->next = tail;
      x->prev = temp;
      temp->next = x;
      tail->prev = x;
    }

    void removeLastNode(Node<K,V>* x) {
       Node<K,V>* prev = x->prev;
       Node<K,V>* next = x->next;
       prev->next = next;
       next->prev = prev;
       x->next = x->prev = nullptr;
    }

};

int main() {
  MyLinkedHashMap<int, int> map;
  map.put('a', 1);
  map.put('b', 2);
  map.put('c', 3);
  map.put('d', 4);
  map.put('e', 5);

  for(const auto& key : map.keys()){
     cout<<key<<" ";
  }
  cout<<endl;

  map.remove('c');

  for(const auto& key : map.keys())
  {
    cout<<key<<" ";
  }
  cout<<endl;
  return 0;
}