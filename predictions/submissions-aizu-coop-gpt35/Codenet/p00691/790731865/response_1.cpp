int calc(int z) {
  int z3 = z * z * z;
  int j3 = nr(z3);
  int ret = z3;
  for (int i = 1; i < z; i++) {
    int i3 = i * i * i;
    if (i3 + j3 >= z3)
      break;
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}