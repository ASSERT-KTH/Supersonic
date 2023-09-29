c[5004], d[5004], m, t, u, i, f = "%d\n";
int main() {
  scanf("%d", &c[0]);
  for (i = 1; i <= c[0]; ++i)
    scanf(f, &c[i]);
  for (i = 0; ~scanf(f, &t);) {
    for (u = i = 0, m = -1e9; i++ < c[0]; t = d[i], d[i] = m < u ? m : u)
      u = t == c[i] ? d[i] + 1 : u;
    m = !printf(f, m);
  }
}