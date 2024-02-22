#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
struct Tree {
  //...
};
template <int N> struct HLComp_Y {
  vector<int> g[N];
  //...
};
const int MN = 220100;
HLComp_Y<MN> hl;
inline int getint() {
  //...
}
inline void putint(int d) {
  //...
}
int main2() {
  int n, q;
  n = getint();
  q = getint();
  for (int i = 0; i < n; i++) {
    int w;
    w = getint();
    hl.data[i] = w;
  }
  for (int i = 0; i < n - 1; i++) {
    int s, e;
    s = getint();
    e = getint();
    s--;
    e--;
    hl.add(s, e);
  }
  hl.init();
  for (int i = 0; i < q; i++) {
    int t, a, b, c;
    t = getint();
    a = getint();
    b = getint();
    c = getint();
    a--;
    b--;
    if (t == 1) {
      hl.path_set(a, b, c);
    } else {
      auto n = hl.path_get(a, b);
      putint((n.mv < 0) ? n.mv : n.ma);
      putchar_unlocked('\n');
    }
  }
  return 0;
}
signed main() {
  //...
  main2();
  //...
  return 0;
}