R[99];
main() {
  for (int i = 0, h = 0, b = 0; read(0, R, 1); ++i) {
    if (i > 9) {
      i = h = b = !printf("%d %d\n", h, b - h);
      for (int j = 0; j < 99; ++j) {
        R[j] = 232;
      }
    }
    b += R[0];
    h += !(R[0] ^= 1 << i % 5);
  }
}