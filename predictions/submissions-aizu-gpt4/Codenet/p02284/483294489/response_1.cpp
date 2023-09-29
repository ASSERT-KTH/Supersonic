#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> tree;

void insert(int k) {
  tree.insert(k);
}

bool find(int k) {
  return tree.find(k) != tree.end();
}

void print() {
  for(const auto& e : tree) {
    cout << " " << e;
  }
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