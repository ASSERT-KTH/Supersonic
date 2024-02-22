int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  uint32 n, q;
  scanf("%d %d", &n, &q);
  std::vector<douse> a(n);
  int32 t1;
  for (uint32 i = 0; i < n; ++i) {
    scanf("%d", &t1);
    a[i] = douse(t1, t1, t1, t1, 1);
  }
  link_cut_tree<douse, ass> L(a);
  uint32 t2, t3;
  for (uint32 i = 0; i < n - 1; ++i) {
    scanf("%d %d", &t2, &t3);
    L.link(t2 - 1, t3 - 1);
  }
  uint32 t4;
  for (uint32 i = 0; i < q; ++i) {
    scanf("%d %d %d %d", &t2, &t3, &t4, &t1);
    if (t2 == 1) {
      L.update(t3 - 1, t4 - 1, ass(t1));
    } else {
      printf("%d\n", L.path(t3 - 1, t4 - 1).all);
    }
  }
  return 0;
}