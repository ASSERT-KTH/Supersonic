inline gtype dot(const Point &a, const Point &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}

inline gtype cross(const Point &a, const Point &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

bool operator<(const Point &a, const Point &b) {
  return make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag());
}