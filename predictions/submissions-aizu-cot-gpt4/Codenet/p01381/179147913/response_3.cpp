#include <iostream>
#include <vector>
#include <string>
using namespace std;
constexpr int N = 1e6 + 2;
int p[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  while (cin >> n >> k) {
    if (n / 2 < k) {
      cout << "-1\n";
      continue;
    }
    p[0] = 0;
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }
    for (int i = 0; i < k; i++) {
      string output;
      for (int j = 0; j < n - 1; j++) {
        int a = (p[j] + i) % n + 1;
        int b = (p[j + 1] + i) % n + 1;
        output += to_string(a) + ' ' + to_string(b) + '\n';
      }
      cout << output;
    }
  }
  return 0;
}