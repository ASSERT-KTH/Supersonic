#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 

  int n, k;
  vector<int> p;
  while (cin >> n >> k) {
    if (n / 2 < k) {
      cout << "-1\n";
      continue;
    }
    p.resize(n + 2);
    p[0] = 0;
    if (k != 0) {
      for (int i = 1; i < n; i += 2) {
        p[i] = i / 2 + 1;
        p[i + 1] = n - p[i];
      }
    }
    for (int i = 0; i < k; i++) {
      string output;
      for (int j = 0; j < n - 1; j++) {
        int a = p[j] + i;
        if (a >= n) a -= n;
        a++;
        int b = p[j + 1] + i;
        if (b >= n) b -= n;
        b++;
        output.append(to_string(a) + " " + to_string(b) + "\n");
      }
      cout << output;
    }
  }
  return 0;
}