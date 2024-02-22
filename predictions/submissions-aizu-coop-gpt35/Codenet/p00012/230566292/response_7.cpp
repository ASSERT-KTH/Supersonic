enum CCWiseState {
  ONLINE_FRONT = -2,
  CLOCKWISE,
  ON_SEGMENT,
  COUNTER_CLOCKWISE,
  ONLINE_BACK,
};
CCWiseState ccwise(Point a, Point b, Point c) {
  Point relative_b = b - a;
  Point relative_c = c - a;
  double cross_product = cross_prod(relative_b, relative_c);
  double dot_product = dot_prod(relative_b, relative_c);
  double norm_b = norm(relative_b);
  double norm_c = norm(relative_c);

  switch (0) {
    case 0:
      if (cross_product > 0) {
        return COUNTER_CLOCKWISE;
      }
    case 1:
      if (cross_product < 0) {
        return CLOCKWISE;
      }
    case 2:
      if (dot_product < 0) {
        return ONLINE_BACK;
      }
    case 3:
      if (norm_b < norm_c) {
        return ONLINE_FRONT;
      }
  }

  return ON_SEGMENT;
}