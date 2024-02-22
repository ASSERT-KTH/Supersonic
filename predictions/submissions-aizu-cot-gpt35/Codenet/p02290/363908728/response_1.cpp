Point projection(const Point &a, const Point &b) {
  return a * dot(b, a) / norm(a);
}