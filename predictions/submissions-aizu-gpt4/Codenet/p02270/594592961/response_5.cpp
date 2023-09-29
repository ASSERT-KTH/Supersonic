#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Input(const int n) {
  vector<int> W(n);
  for (int i = 0; i < n; i++) {
    cin >> W[i];
  }
  return W;
}

bool IsAllLoaded(int P, vector<int> &W, int k) {
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

int Calc(vector<int> &W, int k) {
  int left = *max_element(W.begin(), W.end());
  int right = accumulate(W.begin(), W.end(), 0);
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (IsAllLoaded(mid, W, k)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return right;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> W = Input(n);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}