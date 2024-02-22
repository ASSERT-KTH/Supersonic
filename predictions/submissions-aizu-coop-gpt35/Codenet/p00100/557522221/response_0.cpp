#include <iostream>
#include <vector>
using namespace std;

const int MAX_I = 1000000;

int main() {
  int n, i;
  while (cin >> n, n) {
    vector<long long> sums(MAX_I + 1, 0);
    long long p, q, s = 0;

    while (n--) {
      cin >> i >> p >> q;
      sums[i] += p * q;
    }

    for (i = 0; i <= MAX_I; i++) {
      if (sums[i] >= 1000000) {
        s = 1;
        cout << i << endl;
      }
    }

    if (!s)
      cout << "NA" << endl;
  }
}