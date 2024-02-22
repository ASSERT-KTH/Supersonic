double dot(const P& p) const {
  return x * p.x + y * p.y;
}

double cross(const P& p) const {
  return x * p.y - y * p.x;
}

int ccw(const P& p1, const P& p2) const {
  double c = cross(p1, p2);
  if (c > EPS) return 1;
  if (c < -EPS) return -1;
  if (dot(p1, p2) < -EPS) return 2;
  if (norm() < p2.norm()) return -2;
  return 0;
}