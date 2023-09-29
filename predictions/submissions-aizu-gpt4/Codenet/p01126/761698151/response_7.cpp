#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a;
  int amida[101][1001] = {{0}};
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }
    for (int j = 1000; j > 0; j--) {
      if (amida[a][j] == 1)
        a++;
      else if (a > 1 && amida[a - 1][j] == 1)
        a--;
    }
    cout << a << '\n';
    fill(&amida[0][0], &amida[0][0] + sizeof(amida) / sizeof(int), 0); 
  }
  return 0;
}