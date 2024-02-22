#include <iostream>
using namespace std;

int main() {
  int n, i;
  while (cin >> n, n) {
    long long p, q, sum = 0;
    bool found = false;
    while (n--) {
      cin >> i >> p >> q;
      sum += p * q;
      if (!found && sum >= 1000000) {
        found = true;
        cout << i << endl;
      }
    }
    if (!found)
      cout << "NA" << endl;
  }
}