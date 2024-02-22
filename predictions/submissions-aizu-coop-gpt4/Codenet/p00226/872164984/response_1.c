int R[32]; // Using int array to hold the bits
int i, h, b;
int main(int c) {
  int chunk;
  char buffer[4096]; // Buffer to read data in chunks
  while ((chunk = read(0, buffer, sizeof(buffer))) > 0) { // Reading data in chunks
    for (int j = 0; j < chunk; j++) {
      c = buffer[j];
      b += !!R[c], h += !(R[c] ^= 1 << i % 5);
      if (++i > 9) { // Resetting counters after every 10 iterations
        printf("%d %d\n", h, b - h);
        memset(R, i = h = b = 0, sizeof(R));
      }
    }
  }
}