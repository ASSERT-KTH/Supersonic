#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> nodes;

int main() {
  int n, x;
  string com;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> com;
    if (com == "insert") {
      cin >> x;
      nodes[x] = true;
    } else if (com == "print") {
      for (const auto &node : nodes)
        cout << node.first << " ";
      cout << endl;
    } else if (com == "find") {
      cin >> x;
      if (nodes.find(x) != nodes.end())
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}