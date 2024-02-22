#define NDEBUG
#include <iostream>
#include <vector>
using namespace std;

struct LCNode {
  typedef LCNode *NP;
  typedef int D;
  static const int INF = 1LL << 25;
  static const int DF = 1LL << 25;

  NP p, l, r;
  short sz;
  int v, sm, lz;
  int lsm, rsm, ma, mv;
  bool rev;

  LCNode(D v) : p(NULL), l(nullptr), r(nullptr), sz(1), v(v), sm(v), lz(DF), rev(false),
                lsm(max(v, 0)), rsm(max(v, 0)), ma(max(v, 0)), mv(v) {}

  int pos() {
    if (p) {
      return (p->l == this) ? -1 : 1;
    }
    return 0;
  }

  void rot() {
    NP q = p, qq = q->p;
    int qp = q->pos();
    if (q->l == this) {
      q->l = r;
      if (r) r->p = q;
      r = q;
      q->p = this;
    } else {
      q->r = l;
      if (l) l->p = q;
      l = q;
      q->p = this;
    }
    q->update();
    update();
    p = qq;
    if (!qp) return;
    if (qp == -1) {
      qq->l = this;
    } else {
      qq->r = this;
    }
    qq->update();
  }

  void splay() {
    supush();
    int ps;
    while ((ps = pos())) {
      int pps = p->pos();
      if (!pps) {
        rot();
      } else if (ps == pps) {
        p->rot();
        rot();
      } else {
        rot();
        rot();
      }
    }
  }

  void expose() {
    NP u = this;
    do {
      u->splay();
    } while ((u = u->p));
    splay();
  }

  void push() {
    if (rev) {
      if (l) l->revdata();
      if (r) r->revdata();
      rev = false;
    }
    if (lz != DF) {
      if (l) l->lzdata(lz);
      if (r) r->lzdata(lz);
      lz = DF;
    }
  }

  void supush() {
    if (pos()) {
      p->supush();
    }
    push();
  }

  void revdata() {
    swap(l, r);
    swap(lsm, rsm);
    rev ^= true;
  }

  void lzdata(D d) {
    v = d;
    sm = sz * d;
    lsm = rsm = ma = max(0, sm);
    mv = d;
    lz = d;
  }

  LCNode* update() {
    sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0);
    sm = v + (l ? l->sm : 0) + (r ? r->sm : 0);
    lsm = max(l ? l->lsm : 0, (l ? l->sm : 0) + v + (r ? r->lsm : 0));
    rsm = max(r ? r->rsm : 0, (r ? r->sm : 0) + v + (l ? l->rsm : 0));
    ma = max(max(l ? l->rsm : 0, 0) + v + (r ? r->lsm : 0), max(l ? l->ma : 0, r ? r->ma : 0));
    mv = max(v, max(l ? l->mv : v, r ? r->mv : v));
    return this;
  }

  void evert() {
    expose();
    revdata();
  }
};

const int MN = 201000;
vector<LCNode> tr(MN);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
    cin >> t >> a >> b >> c;
    a--;
    b--;
    if (t == 1) {
      tr[a].evert();
      tr[b].expose();
      tr[b].lzdata(c);
    } else {
      tr[a].evert();
      tr[b].expose();
      int d = (tr[b].mv < 0) ? tr[b].mv : tr[b].ma;
      cout << d << "\n";
    }
  }
  return 0;
}