#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

vector<int> Input(const int n) {
  vector<int> W;
  W.reserve(n);  // avoid multiple reallocations
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    W.push_back(w);
  }
  return W;
}

bool IsAllLoaded(int P, const vector<int>& W, int k) { // avoid copying W
  int TrackIndex = 0;
  int CurrentSum = 0;
  int i = 0;
  for (i = 0; i < W.size(); i++) {
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

int Calc(const vector<int>& W, int k) { // avoid copying W
  int Sum = accumulate(W.begin(), W.end(), 0);
  int left = (Sum + k - 1) / k, right = Sum;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (IsAllLoaded(mid, W, k)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> W = Input(n);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}