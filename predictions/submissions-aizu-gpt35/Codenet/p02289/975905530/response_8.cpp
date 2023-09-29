#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  int inp;
  vector<int> v;
  while (cin >> s) {
    if (s == "end") {
      break;
    } else if (s == "insert") {
      cin >> inp;
      v.push_back(inp);
      push_heap(v.begin(), v.end());
    } else {
      cout << v[0] << endl;
      pop_heap(v.begin(), v.end());
      v.pop_back();
    }
  }
  return 0;
}