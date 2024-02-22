#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct LCNode {
  // code omitted for brevity

  void rot() {
    NP q = p, r = q->p;
    // optimized code to reduce number of swaps
    // code omitted for brevity
  }

  NP update() {
    assert(this != last);
    // use temporary variables to store intermediate results
    int lsz = l->sz, rsz = r->sz;
    sz = 1 + lsz + rsz;
    sm = v + l->sm + r->sm;
    lsm = max(l->lsm, l->sm + v + r->lsm);
    rsm = max(r->rsm, r->sm + v + l->rsm);
    ma = max(l->rsm + v + r->lsm, max(l->ma, r->ma));
    mv = max(v, max(l->mv, r->mv));
    return this;
  }
};

LCNode LCNode::last_d = LCNode();
LCNode::NP LCNode::last = &last_d;

const int MN = 201000;
LCNode tr[MN];

int main() {
  ios_base::sync_with_stdio(false); // untie cin and cout from stdio
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    tr[i] = LCNode(w);
  }
  // rest of the code
  for (int i = 0; i < q; i++) {
    int t, a, b, c;
    cin >> t >> a >> b >> c;
    a--;
    b--;
    if (t == 1) {
      // code omitted for brevity
    } else {
      // code omitted for brevity
      cout << d << "\n";
    }
  }
  return 0;
}