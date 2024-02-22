...
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
...
inline int ccw(const P &s, const P &t, const P &p, int adv = 0) {
  int res = sig(outp(t - s, p - s));
  if (res || !adv)
    return res;
  int inp_res = sig(inp(t - s, p - s));
  if (inp_res < 0)
    return -2;
  if (sig(inp(s - t, p - t)) < 0)
    return 2;
  return 0;
}
...
Arrangement(vector<S> seg) {
  int m = seg.size();
  p.reserve(m * 2);
  REP(i, m) {
    p.push_back(seg[i][0]);
    p.push_back(seg[i][1]);
    REP(j, i)
    if (sig(outp(seg[i].dir(), seg[j].dir())) &&
        intersect(seg[i], seg[j]) == TRUE)
        p.push_back(crosspoint(seg[i], seg[j]));
  }
...