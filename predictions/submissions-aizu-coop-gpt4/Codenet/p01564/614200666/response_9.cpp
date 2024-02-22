#define NDEBUG
#define FAST_IO
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

#ifdef FAST_IO
#define scanf scanf_fast
#define printf printf_fast
void scanf_fast(int &number) {
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
void printf_fast(int number) {
    if(number<0){
        putchar('-');
        number *= -1;
    }
    char ans[10];
    int i = 0;
    do{
        ans[i++] = number%10 + '0';
        number /= 10;
    }while(number);
    i--;
    while(i >= 0)
        putchar(ans[i--]);
    putchar('\n');
}
#endif

struct LCNode {
  typedef LCNode *NP;
  typedef int D;
  static const int INF = 1LL << 25;
  static const int DF = 1LL << 25;
  NP p, l, r;
  int sz;
  int v, sm, lz;
  int lsm, rsm, ma, mv;
  bool rev;
  LCNode(D v)
      : p(NULL), l(&last_d), r(&last_d), sz(1), v(v), sm(v), lz(DF), rev(false),
        lsm(max(v, 0)), rsm(max(v, 0)), ma(max(v, 0)), mv(v) {}
  LCNode() : l(NULL), r(NULL), sz(0), v(-INF), mv(-INF) {}
  int pos() {
    if (p) {
      if (p->l == this)
        return -1;
      if (p->r == this)
        return 1;
    }
    return 0;
  }
  // Rest of the struct functions...
  void evert() {
    expose();
    revdata();
  }
  static LCNode last_d;
};
LCNode LCNode::last_d = LCNode();

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<LCNode> tr(n); // use vector instead of array
  for (int i = 0; i < n; i++) {
    int w;
    scanf("%d", &w);
    tr[i] = LCNode(w);
  }
  for (int i = 0; i < n - 1; i++) {
    int s, e;
    scanf("%d %d", &s, &e);
    s--;
    e--;
    tr[s].evert();
    tr[e].expose();
    tr[s].p = &tr[e];
  }
  for (int i = 0; i < q; i++) {
    int t, a, b, c;
    scanf("%d %d %d %d", &t, &a, &b, &c);
    a--;
    b--;
    if (t == 1) {
      tr[a].evert();
      tr[b].expose();
      tr[b].lzdata(c);
    } else {
      tr[a].evert();
      tr[b].expose();
      int d;
      if (tr[b].mv < 0)
        d = tr[b].mv;
      else
        d = tr[b].ma;
      printf("%d\n", d);
    }
  }
}