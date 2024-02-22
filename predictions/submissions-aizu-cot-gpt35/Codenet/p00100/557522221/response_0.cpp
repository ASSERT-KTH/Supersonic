#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, i;
  while (cin >> n, n) {
    vector<long long> sums(1000000, 0);
    vector<int> vec;
    long long p, q, s = 0;
    while (n--) {
      cin >> i >> p >> q;
      if (sums[i] == 0)
        vec.push_back(i);
      sums[i] += p * q;
    }
    for (int i = 0; i < vec.size(); i++) {
      if (sums[vec[i]] >= 1000000) {
        s = 1;
        cout << vec[i] << endl;
      }
    }
    if (!s)
      cout << "NA" << endl;
  }
}