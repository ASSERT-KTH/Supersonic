char R[100] = {0};
int i = 0, h = 0, b = 0;

int main() {
  int c;
  while ((c = getchar()) != EOF) {
    if (i++ > 9) {
      h = b = 0;
      memset(R, 0, sizeof(R));
    }
    b += !!R[c];
    h += !(R[c] ^= 1 << i % 5);
    if (i > 9) printf("%d %d\n", h, b - h);
  }
  return 0;
}