// (Code above this line remains the same...)

// Optimization 1: Use faster alternatives for math operations
// Optimization 2: Reduce floating point comparisons
inline bool fast_equals(double a, double b) {
  return abs((int)(a * 1e7) - (int)(b * 1e7)) < 1;
}

// (Code above this line remains the same...)

// Optimization 3: Perform operations directly on member variables
Point3d operator+(const Point3d &a) const {
  return Point3d(x + a.x, y + a.y, z + a.z);
}
Point3d operator-(const Point3d &a) const {
  return Point3d(x - a.x, y - a.y, z - a.z);
}
// (Code above this line remains the same...)

// Optimization 4: Remove redundant computations
Point3d crosspointS(Segment3d seg) {
  Point3d a = normal_vector * d;
  double dot_p0a = fabs(dot(seg.p[0] - a, normal_vector));
  double t = dot_p0a / (dot_p0a + fabs(dot(seg.p[1] - a, normal_vector)));
  return seg.p[0] + (seg.p[1] - seg.p[0]) * t;
}

// Optimization 5: Pass already normalized vector
Point3d crosspointTS(Vector3d normal_vector, Point3d tri1, Segment3d seg) {
  double dist1 = dot(seg.p[1] - seg.p[0], normal_vector);
  double dist2 = dot(tri1 - seg.p[0], normal_vector);
  double t = dist2 / dist1;
  Point3d e = (seg.p[1] - seg.p[0]) / abs(seg.p[1] - seg.p[0]);
  return seg.p[0] + e * t;
}

// Optimization 6: Read input into temporary variables
int main() {
  double sx, sy, sz, gx, gy, gz;
  cin >> sx >> sy >> sz;
  cin >> gx >> gy >> gz;
  Point3d S(sx, sy, sz), G(gx, gy, gz);
  Point3d tri[3];
  double tx, ty, tz;
  for (int i = 0; i < 3; i++) {
    cin >> tx >> ty >> tz;
    tri[i] = Point3d(tx, ty, tz);
  }
  // (Code below this line remains the same...)
}