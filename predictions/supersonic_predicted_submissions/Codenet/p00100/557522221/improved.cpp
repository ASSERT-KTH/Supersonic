#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  int n, i;
  while (cin >> n, n) {
    map<int, long long> m;
    vector<int> vec;
    long long p, q;
    bool s = 0;
    while (n--) {
      cin >> i >> p >> q;
      if (!m[i])
        vec.push_back(i);
      m[i] += p * q;
    }
    for (int i = 0; i < vec.size(); i++) {
      if (m[vec[i]] >= 1000000) {
        s = 1;
        cout << vec[i] << endl;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}
