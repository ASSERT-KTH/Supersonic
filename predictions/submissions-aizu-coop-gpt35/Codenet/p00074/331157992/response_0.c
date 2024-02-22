main(h, m, s, t) {
  int remainingSeconds;
  for (; scanf("%d%d%d", &h, &m, &s) * -~h;) {
    remainingSeconds = (120 - h * 60 - m) * 60 - s;
    for (t = remainingSeconds, h = 2; h--; t *= 3) {
      printf("%02d:%02d:%02d\n", t / 3600, t / 60 % 60, t % 60);
    }
  }
}