c[5004], d[5004], m, t, u, i, f = "%d\n";
int main() {
  scanf("%d%*d", c);
  for (i = 1; i <= *c; i++) {
    scanf(f, c + i);
  }
  for (; ~scanf(f, c);) {
    m = t = u = 0;
    for (i = 1; i <= *c; i++) {
      t = d[i];
      d[i] = m < u ? m = u : u;
      u = *c - c[i] ? u : t + 1;
    }
    m = !printf(f, m);
  }
  return 0;
}