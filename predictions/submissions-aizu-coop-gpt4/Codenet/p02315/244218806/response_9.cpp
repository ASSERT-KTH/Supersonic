#include <iostream>
#include <vector>
#include <algorithm> // for std::max
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N), dp_previous(W+1, 0), dp_current(W+1, 0);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];
    
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j - w[i] < 0) {
        dp_current[j] = dp_previous[j];
      } else {
        dp_current[j] = max(dp_previous[j], dp_previous[j - w[i]] + v[i]);
      }
    }
    dp_previous = dp_current; // copy current dp to previous dp
  }
  cout << dp_previous[W] << endl;
  return 0;
}