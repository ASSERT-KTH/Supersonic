#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, i;
  while (cin >> n, n) {
    long long values[1000000] = {0};
    bool keys[1000000] = {false};
    bool found = false;

    while (n--) {
      cin >> i;
      long long p, q;
      cin >> p >> q;

      if (!keys[i]) {
        keys[i] = true;
      }

      values[i] += p * q;

      if (values[i] >= 1000000 && !found) {
        found = true;
        cout << i << endl;
      }
    }

    if (!found) {
      cout << "NA" << endl;
    }
  }
}