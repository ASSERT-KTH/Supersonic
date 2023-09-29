c[5004], d[5004], m, t, u, i, f = "%d\n";
int main() {
  scanf("%d%*d", c);
  for (i = 1; i <= *c; ++i) {
    scanf(f, c + i);
  }
  for (m = i = 0; scanf(f, &u) > 0; m = d[*c], d[*c] = m < u ? m : u)
    for (t = 0; i-- > 1; d[i] = m < t ? m : t, t = m)
      m = c[i] == u ? d[i] + 1 : t + 1;
  printf(f, m);
  return 0;
}