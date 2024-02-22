#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> value(N), weight(N);
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];
  vector<int> dp_prev(W+1, 0), dp_cur(W+1, 0);
  for (int i = 0; i < N; i++) {
    for (int w = 0; w <= W; w++) {
      if (w >= weight[i])
        dp_cur[w] = max(dp_prev[w - weight[i]] + value[i], dp_prev[w]);
      else
        dp_cur[w] = dp_prev[w];
    }
    dp_prev = dp_cur;
  }
  cout << dp_cur[W] << endl;
  return 0;
}