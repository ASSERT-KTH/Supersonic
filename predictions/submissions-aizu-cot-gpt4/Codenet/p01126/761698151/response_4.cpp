#include <iostream>
#include <map>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, a;
  int h, p, q;
  map<pair<int, int>, int> amida;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    amida.clear();
    for (int i = 0; i < m; ++i) {
      cin >> h >> p >> q;
      amida[make_pair(p, h)] = 1;
    }
    for (int j = 1000; j > 0; --j) {
      if (amida[make_pair(a, j)] == 1)
        ++a;
      else if (amida[make_pair(a - 1, j)] == 1)
        --a;
    }
    cout << a << '\n';
  }

  return 0;
}