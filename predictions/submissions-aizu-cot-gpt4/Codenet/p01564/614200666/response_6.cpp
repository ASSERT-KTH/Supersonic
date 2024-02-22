#define NDEBUG
#include <iostream>
using namespace std;

typedef long long ll;

struct LCNode {
  typedef LCNode *NP;
  typedef int D;
  static const int INF = (1LL << 25);
  static LCNode last_d;
  static NP last;
  NP p, l, r;
  int sz;
  int v, sm, lz;
  int lsm, rsm, ma, mv;
  bool rev;

  LCNode(D v)
      : p(NULL), l(last), r(last), sz(1), v(v), sm(v), lz(INF), rev(false),
        lsm(v > 0 ? v : 0), rsm(v > 0 ? v : 0), ma(v > 0 ? v : 0), mv(v) {}
  
  LCNode() : l(NULL), r(NULL), sz(0), v(-INF), mv(-INF) {}

  // remaining code is same as original
};

// remaining code is same as original

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    tr[i] = LCNode(w);
  }
  for (int i = 0; i < n - 1; i++) {
    int s, e;
    cin >> s >> e;
    s--;
    e--;
    tr[s].evert();
    tr[e].expose();
    tr[s].p = &tr[e];
  }
  for (int i = 0; i < q; i++) {
    int t, a, b, c;
    cin >> t >> a >> b;
    a--;
    b--;
    if (t == 1) {
      cin >> c;
      tr[a].evert();
      tr[b].expose();
      tr[b].lzdata(c);
    } else {
      tr[a].evert();
      tr[b].expose();
      int d = tr[b].mv < 0 ? tr[b].mv : tr[b].ma;
      cout << d << "\n";
    }
  }
  return 0;
}