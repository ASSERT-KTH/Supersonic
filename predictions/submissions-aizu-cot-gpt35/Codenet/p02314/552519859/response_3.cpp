#include <iostream>
#include <cstring>
using namespace std;

const int INF = 2000000000;

int main() {
  int n, m;
  cin >> n >> m;

  int c[21];
  int mini[50001];
  memset(mini, INF, sizeof(mini));

  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }

  // Selection Sort
  for (int i = 1; i <= m; i++) {
    int minIndex = i;
    for (int j = i + 1; j <= m; j++) {
      if (c[j] < c[minIndex]) {
        minIndex = j;
      }
    }
    swap(c[i], c[minIndex]);
  }

  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = min(mini[j], mini[j - c[i]] + 1);
    }
  }

  cout << mini[n] << endl;

  return 0;
}