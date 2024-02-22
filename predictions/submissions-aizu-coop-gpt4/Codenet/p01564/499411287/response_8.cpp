while (c = getchar_unlocked(), '0' <= c && c <= '9') {
  res = res * 10 + (c - '0');
}