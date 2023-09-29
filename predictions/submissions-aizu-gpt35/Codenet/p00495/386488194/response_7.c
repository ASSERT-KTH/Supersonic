c[5004], d[5004], m, t, u, i, f = "%d\n";
int main() {
  scanf("%d%*d", c);
  for (i = 1; i <= c[0]; ++i) scanf(f, c + i);
  while (~scanf(f, &u)) {
    m = 0;
    for (i = 1; i <= c[0]; ++i) {
      t = d[i];
      d[i] = m < u - c[i] ? m : u - c[i];
      m = m < t + 1 - c[i] ? m : t + 1 - c[i];
    }
  }
  printf(f, m);
  return 0;
}