#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m, a;
  int amida[101][1001];
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    fill(&amida[0][0], &amida[0][0] + sizeof(amida) / sizeof(int), 0);
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }
    for (int j = 1000; j > 0; j--) {
      if (amida[a][j])
        a++;
      else if (amida[a - 1][j])
        a--;
    }
    cout << a << '\n';
  }
  return 0;
}