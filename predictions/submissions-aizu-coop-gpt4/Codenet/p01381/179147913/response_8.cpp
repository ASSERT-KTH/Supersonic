#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k) {
    if (n / 2 < k) {
      cout << "-1" << endl;
      continue;
    }
    vector<int> p(n + 2);
    p[0] = 0;
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }
    stringstream ss;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n - 1; j++) {
        int a = (p[j] + i) % n + 1;
        int b = (p[j + 1] + i) % n + 1;
        ss << ((i != 0 && j == 0) ? "\n" : "") << a << " " << b << ((j < n - 2) ? "\n" : "");
      }
    }
    cout << ss.str();
  }
}