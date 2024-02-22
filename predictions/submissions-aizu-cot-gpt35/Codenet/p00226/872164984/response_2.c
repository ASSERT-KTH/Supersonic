R[99];
i;

int main(c) {
  for (; read(0, &c, 1); ++i >= 10 && memset(R, 0, sizeof(R))) {
    int b = 0;
    for (int j = 0; j < 99; j++) {
      b += !!R[c];
      R[c] ^= 1 << (i % 5);
    }
    printf("%d\n", b);
  }
}