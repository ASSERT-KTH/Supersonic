int ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  double cross_ab = cross(a, b);
  double dot_ab = dot(a, b);
  double a_norm = a.norm();

  if (cross_ab > EPS)
    return COUNTER_CLOCKWISE;
  if (cross_ab < -EPS)
    return CLOCKWISE;
  if (dot_ab < -EPS)
    return ONLINE_BACK;
  if (a_norm < b.norm())
    return ONLINE_FRONT;
  return ON_SEGMENT;
}