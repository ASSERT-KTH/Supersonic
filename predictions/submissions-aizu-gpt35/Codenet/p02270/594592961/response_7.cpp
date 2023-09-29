#include <iostream>
#include <vector>
using namespace std;
vector<int> Input(const int n) {
  vector<int> W(n);
  for (int i = 0; i < n; i++) {
    cin >> W[i];
  }
  return W;
}
bool IsAllLoaded(int P, const vector<int>& W, int k) {
  int CurrentSum = 0;
  for (int i = 0; i < W.size(); i++) {
    if (W[i] > P) {
      return false;
    }
    CurrentSum += W[i];
    if (CurrentSum > P) {
      CurrentSum = W[i];
      k--;
    }
    if (k == 0) {
      return false;
    }
  }
  return true;
}
int Calc(const vector<int>& W, int k) {
  int Sum = 0, MaxWeight = 0;
  for (auto weight : W) {
    Sum += weight;
    MaxWeight = max(MaxWeight, weight);
  }
  int l = MaxWeight, r = Sum;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (IsAllLoaded(mid, W, k)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  auto W = Input(n);
  int P = Calc(W, k);
  cout << P << '\n';
  return 0;
}