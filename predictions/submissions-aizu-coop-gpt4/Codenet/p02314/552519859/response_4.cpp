#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 2000000000;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(m+1);
  vector<int> mini(n+1, INF); // Dynamically allocate to size n+1 and initialize to INF

  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }

  mini[0] = 0; // You need 0 coins to make a sum of 0

  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) { // Start from c[i] and go up to n
      mini[j] = min(mini[j], mini[j - c[i]] + 1);
    }
  }

  cout << mini[n] << endl;

  return 0;
}