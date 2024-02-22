int numCoins[T];

void precalculateNumCoins() {
  for (int v = 0; v < T; v++) {
    int ans = 0;
    for (int i = 5; i >= 0; i--) {
      ans += v / C[i];
      v %= C[i];
    }
    numCoins[v] = ans;
  }
}