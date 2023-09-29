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
      k--;
      if (k == 0) {
        return false;
      }
      CurrentSum = W[i];
    }
  }
  return true;
}

int Calc(const vector<int>& W, int k, int lo, int hi) {
  if (lo + 1 == hi) {
    return hi;
  }
  int mid = (lo + hi) / 2;
  if (IsAllLoaded(mid, W, k)) {
    return Calc(W, k, lo, mid);
  } else {
    return Calc(W, k, mid, hi);
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> W = Input(n);
  int lo = 0, hi = 1e9;
  cout << Calc(W, k, lo, hi) << endl;
  return 0;
}