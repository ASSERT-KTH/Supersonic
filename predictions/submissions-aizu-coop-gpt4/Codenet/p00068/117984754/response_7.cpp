// ...
bool isPointInsidePolygon(vector<L> side, P p) {
  int c = 0, sideSum = side.size();
  vector<double> precomputedCrossProducts(sideSum);
  rep(i, sideSum) {
    precomputedCrossProducts[i] = cross(side[i].p2 - side[i].p1, p - side[i].p1);
  }
  rep(i, sideSum) {
    if (precomputedCrossProducts[i] > 0)
      c++;
  }
  return !(c % sideSum);
}

vector<P> convex_hull(P *ps, int n) {
  sort(ps, ps + n, cmp_x);
  int k = 0;
  vector<P> qs(n * 2);
  qs.reserve(n * 2);  // Preallocate vector
  // ...
}

// ...