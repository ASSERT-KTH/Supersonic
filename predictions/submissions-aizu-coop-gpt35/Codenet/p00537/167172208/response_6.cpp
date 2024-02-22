int main() {
  int N, M, P[100000];
  cin >> N >> M;
  SegmentTree segtree(N);
  for (int i = 0; i < M; i++) {
    cin >> P[i];
    --P[i];
  }
  // ...
  cout << ret << endl;
}