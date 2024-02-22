//... (rest of the code)
bool check(const MSQ &temp, R r, const vector<P> &shoolack, int i, int j) {
  MSQ msq;
  L l = temp.segment(j);
  P gp = shoolack[i] - l[0] * r;
  temp.copy(r, gp, msq);
  vector<P> p;
  P b(-INF, -INF), u(+INF, +INF);
  REP(i, n) {
    L l2(shoolack[i], shoolack[i] + l.dir());
    int f = 0;
    P ll(INF, INF), rr(-INF, -INF);
    auto dir = msq.segment(j).dir();   // Calculate once and use it in the loop
    REP(j, m) {
      const S s = msq.segment(j);
      if (intersect(s, l2)) {
        if (sig(outp(dir, l2.dir()))) {   // Use pre-calculated dir
          const P q = crosspoint(s, l2) - l2[0];
          p.push_back(q);
          ll = min(ll, q);
          rr = max(rr, q);
        }
        f = 1;
      }
    }
    u = min(rr, u);
    b = max(ll, b);
    if (!f)
      return false;
  }
  FOR(q, p) {
    if (*q < b || u < *q)
      continue;
    if ([&]() {
          REP(i, n) if (!convex_contains(msq, gp, shoolack[i] + *q)) return 0;
          return 1;
        }())
      return true;
  }
  return false;
}
//... (rest of the code)