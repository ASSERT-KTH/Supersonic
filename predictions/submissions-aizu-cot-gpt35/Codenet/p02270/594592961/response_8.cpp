#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

bool IsAllLoaded(const vector<int>& W, int P, int k) {
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

int Calc(const vector<int>& W, int k) {
  int Sum = accumulate(W.begin(), W.end(), 0);
  int left = 1;
  int right = Sum;
  int result = 0;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (IsAllLoaded(W, mid, k)) {
      result = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return result;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> W(n);
  for (int i = 0; i < n; i++) {
    cin >> W[i];
  }
  int P = Calc(W, k);
  cout << P << '\n';
  return 0;
}