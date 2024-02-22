#include <iostream>
#include <string>
#include <set>  // We use std::set to represent a balanced BST
using namespace std;

int main() {
  int n, x;
  string com;
  set<int> bst;  // A balanced BST

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> com;
    if (com == "insert") {
      cin >> x;
      bst.insert(x);
    } else if (com == "print") {
      for (const int& key : bst)
        cout << " " << key;
      cout << endl;
    } else if (com == "find") {
      cin >> x;
      if (bst.find(x) != bst.end())
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }

  return 0;
}