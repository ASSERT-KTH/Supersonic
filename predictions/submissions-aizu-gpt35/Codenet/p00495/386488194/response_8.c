c[5004], d[5004], m, t, u, i, f = "%d\n";
int main() {
  scanf("%d%*d", &c[0]);
  for (i = 1; i < c[0] + 1; i++) {
    scanf(f, &c[i]);
  }
  while (~scanf(f, &t)) {
    m = 0;
    for (i = 1; i <= c[0]; i++) {
      u = t - c[i] ? u : t >= c[i] ? d[i] + 1 : 0;
      m = u > m ? u : m;
      d[i] = t >= c[i] ? d[i] : m;
    }
    printf(f, m);
  }
}