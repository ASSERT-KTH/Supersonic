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
    for (int i = 0; i < vec.size(); i++) {
      map<int, long long>::iterator it = m.find(vec[i]);
      if (it->second >= 1000000) {
        s = 1;
        printf("%d\n", it->first);
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}
