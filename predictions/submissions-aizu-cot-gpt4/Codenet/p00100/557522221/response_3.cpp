#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  int n, i;
  while (cin >> n, n) {
    map<int, long long> m;
    vector<int> vec;
    long long p, q, s = 0;
    while (n--) {
      cin >> i >> p >> q;
      if (!m[i])
        vec.push_back(i);
      m[i] += p * q;
    }
    int vecSize = vec.size();
    for (int i = 0; i < vecSize; i++) {
      auto it = m[vec[i]];
      if (it >= 1000000) {
        s = 1;
        cout << vec[i] << endl;
        break;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}