bool point_on_the_triangle3d(Point3d tri1, Point3d tri2, Point3d tri3, Point3d p) {
  Vector3d v1 = tri2 - tri1;
  Vector3d v2 = tri3 - tri2;
  Vector3d v3 = tri1 - tri3;
  Vector3d cp[3] = {cross(v1, p - tri1), cross(v2, p - tri2),cross(v3, p - tri3)};
  double d1 = dot(cp[0], cp[1]);
  double d2 = dot(cp[0], cp[2]);
  if ((!equals(d1, 0.0) && d1 > 0) && (!equals(d2, 0.0) && d2 > 0))
    return true;
  return false;
}

bool Plane3d::intersectS(Segment3d seg) {
  Point3d a = normal_vector * d;
  double res1 = dot(a - seg.p[0], normal_vector);
  double res2 = dot(a - seg.p[1], normal_vector);
  if (res1 > res2)
    swap(res1, res2);
  if ((equals(res1, 0.0) || res1 < 0) && (equals(res2, 0.0) || res2 > 0))
    return true;
  return false;
}

Point3d Plane3d::crosspointS(Segment3d seg) {
  Point3d a = normal_vector * d;
  double dot_p0a = fabs(dot(seg.p[0] - a, normal_vector));
  double dot_p1a = fabs(dot(seg.p[1] - a, normal_vector));
  if (equals(dot_p0a + dot_p1a, 0))
    return seg.p[0];
  return seg.p[0] + (seg.p[1] - seg.p[0]) * (dot_p0a / (dot_p0a + dot_p1a));
}