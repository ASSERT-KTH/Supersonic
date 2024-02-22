// A function like equals, which is called frequently, can be made inline to reduce function call overhead.
inline bool equals(double a, double b) {
    return fabs(a - b) < EPS;
}

// Similarly, the abs function can be made inline.
inline double abs(Point a) {
  return sqrt(a.x * a.x + a.y * a.y);
}

// Computation of cross product of points of two lines, which is done multiple times in the code, can be computed once and stored.
double crossProduct = cross(line1.p1 - line1.p2, line2.p1 - line2.p2);

// Use scanf and printf instead of cin and cout for faster I/O.
int main() {
  int n;
  while (scanf("%d", &n) != EOF && n) {
    Line vec[n];
    for(int i = 0; i < n; i++) 
      scanf("%lf %lf %lf %lf", &vec[i].p1.x, &vec[i].p1.y, &vec[i].p2.x, &vec[i].p2.y);
    compute(vec, n);
  }
  return 0;
}