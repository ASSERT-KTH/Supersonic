// ... Other parts of the code ...

inline double norm(Vector a) { return a.x * a.x + a.y * a.y; }
inline double abs(Vector a) { return sqrt(norm(a)); }
inline double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
inline double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

// ... Other parts of the code ...

double diameter(Polygon s) {
  Polygon p = convex_hull(s);
  int n = p.size();
  if (n == 2)
    return abs(p[0] - p[1]);
  int i = 0, j = 0;
  for (int k = 0; k < n; k++) {
    if (p[i] < p[k])
      i = k;
    if (!(p[j] < p[k]))
      j = k;
  }
  double res = 0;
  int si = i, sj = j;
  while (i != sj || j != si) {
    double absVal = abs(p[i] - p[j]);
    res = max(res, absVal);
    Vector nextI = p[(i + 1) % n] - p[i];
    Vector nextJ = p[(j + 1) % n] - p[j];
    if (cross(nextI, nextJ) < 0.0) {
      i = (i + 1) % n;
    } else {
      j = (j + 1) % n;
    }
  }
  return res;
}

// ... Other parts of the code ...