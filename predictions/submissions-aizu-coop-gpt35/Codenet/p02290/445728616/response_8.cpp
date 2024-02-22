P project(P a, P b, P c) {
  b -= a;
  c -= a;
  return a + b * std::real(c / b);
}