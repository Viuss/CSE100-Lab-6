//Collaborated with Damian Soto and Andre Limos for main function
//Collaborated Andrew Mouillesseaux for miscellaneous parts
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Hash {
  int BUCKET; // how many buckets

  // Pointer to an array containing buckets
  list<int> *table;

public:
  Hash(int b); // Constructor
  //int key;
//insert
  void i(int key);
//delete
  void d(int key); 
//search
  void s(int key);
//output
  void o();

  int hashFunction(int x) { return (x % BUCKET); }

};

Hash::Hash(int b) {
  this->BUCKET = b;
  table = new list<int>[BUCKET];
}

void Hash::i(int key) {
  int index = hashFunction(key);
  table[index].push_front(key);
}

void Hash::d(int key) {
  // get hash index
  int index = hashFunction(key);

  // find
  list<int>::iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++) {
    if (*i == key)
      break;
  }

  // remove if found
  if (i != table[index].end()){
    table[index].erase(i);
    cout << key << ":" << "DELETED" << ";" << endl;
    }
    else if (i == table[index].end())
    //table[index].erase(i);
    cout << key << ":" << "DELETE_FAILED" << ";" << endl;
}

void Hash::s(int key) {
  int flag = 0;
  int index = hashFunction(key);
  int count = 0;
  list<int>::iterator i;
      for (i = table[index].begin(); i != table[index].end(); i++){
        if (*i == key){
        cout << key << ":FOUND_AT" << index << "," << count << ";" << endl;
        flag = 1;
        break;
        }
      count++;
      }
    if (flag == 0) {
      cout << key << ":NOT_FOUND" << ";" << endl;
  }
}
  


// display table
void Hash::o() {
  for (int i = 0; i < BUCKET; i++) {
    cout << i << ":" ;
    for (auto x : table[i])
      cout << x << "->";
    cout << ";" << endl;
  }
}


int main() {
  int len;
  cin >> len;
  Hash h(len);
  int key;
  char c;
do{
  cin >> c;
  switch(c){
  case 'i' :  
    cin >> key;
    h.i(key);
  break;
  
  case 'd' :  
    cin >> key;
    h.d(key);
  break;
  
  case 's' :  
    cin >> key;
    h.s(key);
  break;
  
  case 'o' : 
    h.o();
  break;

  case 'e' :
  break;
  }
  }
  while (c != 'e');
}

