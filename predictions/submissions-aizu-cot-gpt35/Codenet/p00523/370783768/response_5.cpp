bool Find(const int &pos, const int64 &size) {
  int hoge = pos + 1;
  while (hoge < N + pos + 1 && sum[hoge] < sum[pos] + size)
    hoge++;
  if (hoge == N + pos + 1)
    return false;
  int fuga = hoge + 1;
  while (fuga < N + pos + 1 && sum[fuga] < sum[hoge] + size)
    fuga++;
  if (fuga == N + pos + 1)
    return false;
  int foo = fuga + 1;
  while (foo < N + pos + 1 && sum[foo] < sum[fuga] + size)
    foo++;
  return (foo != N + pos + 1);
}