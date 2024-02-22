P project(P a, P b, P c) {
  P b_modified = b - a;
  P c_modified = c - a;
  return a + b_modified * real(c_modified / b_modified);
}