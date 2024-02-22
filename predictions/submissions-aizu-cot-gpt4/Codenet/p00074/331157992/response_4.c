main(h, m, s, t) {
  int t_div_3600, t_div_60;
  for (; scanf("%d%d%d", &h, &m, &s) * -~h;) {
    t = (120 - h * 60 - m) * 60 - s;
    for (h = 2; h--; t *= 3) {
      t_div_3600 = t / 3600;
      t_div_60 = t / 60;
      printf("%02d:%02d:%02d\n", t_div_3600, t_div_60 % 60, t % 60);
    }
  }
}