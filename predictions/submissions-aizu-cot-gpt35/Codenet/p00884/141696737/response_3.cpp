bool isso(long long int a) {
  if (a == 1 || a == 0)
    return false;
  if (a == 2)
    return true;
  if (a % 2 == 0)
    return false;
  for (long long int i = 3; i * i <= a; i += 2) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}