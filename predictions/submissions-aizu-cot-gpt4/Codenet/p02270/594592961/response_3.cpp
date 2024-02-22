#include <iostream>
#include <vector>
using namespace std;

pair<vector<int>, int> Input(const int n) {
  vector<int> W(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> W[i];
    sum += W[i];
  }
  return make_pair(W, sum);
}

bool IsAllLoaded(int P, const vector<int>& W, int k) {
  int TrackIndex = 0;
  int CurrentSum = 0;
  for (int i = 0; i < W.size(); i++) {
    if (W[i] > P) {
      return false;
    }
    if (CurrentSum + W[i] > P) {
      TrackIndex++;
      if (TrackIndex == k) {
        return false;
      }
      CurrentSum = 0;
    }
    CurrentSum += W[i];
  }
  return true;
}

int Calc(const vector<int>& W, int sum, int k) {
  int P = (sum + k - 1) / k;
  while (!IsAllLoaded(P, W, k)) {
    P++;
  }
  return P;
}

int main() {
  int n, k;
  cin >> n >> k;
  auto [W, sum] = Input(n);
  int P = Calc(W, sum, k);
  cout << P << endl;
  return 0;
}