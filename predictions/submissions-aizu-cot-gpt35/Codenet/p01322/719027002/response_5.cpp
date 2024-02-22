#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 8;

int main() {
  int n, m, o[MAX_N];
  char b[MAX_N][MAX_M];
  char l[MAX_M];
  int ans;

  while (true) {
    cin >> n >> m;
    if (!n && !m)
      break;

    ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> b[i] >> o[i];
    }

    int hash[MAX_N];
    memset(hash, 0, sizeof(hash));

    for (int i = 0; i < m; i++) {
      cin >> l;
      for (int j = 0; j < n; j++) {
        if (strncmp(b[j], l, MAX_M) == 0) {
          ans += o[j];
          hash[j] = 1;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (hash[i] == 1) {
        ans += o[i];
      }
    }

    cout << ans << endl;
  }
}