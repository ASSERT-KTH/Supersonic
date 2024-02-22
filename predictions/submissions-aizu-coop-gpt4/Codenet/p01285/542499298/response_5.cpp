Point& operator+=(const Point& p) {
  x += p.x;
  y += p.y;
  return *this;
}