int convex_contains(const MSQ &msq, const P &g, const P &p) {
  const int n = msq.size();
  int a = 0, b = n;
  const P pg = p - g;
  while (a + 1 < b) {
    int c = (a + b) / 2;
    if (outp(msq[a] - g, pg) > 0 && outp(msq[c] - g, pg) < 0)
      b = c;
    else
      a = c;
  }
  b %= n;
  P diff = msq[a] - p;
  if (outp(diff, msq[b] - p) < -EPS)
    return 0;
  return 1;
}