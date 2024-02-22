#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n, i;
  while (cin >> n, n) {
    unordered_map<int, int> m;
    vector<int> vec;
    int p, q;
    bool found = false;
    while (n--) {
      cin >> i >> p >> q;
      if (m.find(i) == m.end())
        vec.push_back(i);
      m[i] += p * q;
    }
    for (int i : vec) {
      if (m[i] >= 1000000) {
        found = true;
        cout << i << endl;
      }
    }
    if (!found)
      cout << "NA" << endl;
  }
}