c[5004], d[5004], m, t, u, i, f = "%d\n";
int main() {
  scanf("%d%*d", c);
  for (i = 1; i <= *c; ++i) {
    scanf(f, c + i);
  }
  while (~scanf(f, &i)) {
    for (u = t = 0; t <= m; t++) {
      u = i == c[t] ? d[t] + 1 : u;
      d[t] = m < u ? m = u : d[t];
    }
  }
  printf(f, m);
  return 0;
}