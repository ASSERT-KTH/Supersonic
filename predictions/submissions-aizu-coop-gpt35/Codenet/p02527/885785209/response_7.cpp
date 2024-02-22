T *piv = l;
for (T *i = l + 1; i < r; i++) {
  if (*i > *piv) {
    piv = i;
  }
}