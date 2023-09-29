#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> treeSet;

void insert(int k) {
  treeSet.insert(k);
}

bool find(int k) {
  return treeSet.find(k) != treeSet.end();
}

void print() {
  for (const auto& item : treeSet)
    cout << " " << item;
  cout << endl;
}

int main() {
  int n, x;
  string com;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> com;
    if (com == "insert") {
      cin >> x;
      insert(x);
    } else if (com == "print") {
      print();
    } else if (com == "find") {
      cin >> x;
      if (find(x))
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}