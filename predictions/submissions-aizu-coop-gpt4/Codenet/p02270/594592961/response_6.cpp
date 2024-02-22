#include <iostream>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> Input(const int n) {
  vector<int> W(n);
  for (int i = 0; i < n; i++) {
    cin >> W[i];
  }
  return W;
}

map<pair<int, int>, bool> cache;

bool IsAllLoaded(int P, const vector<int>& W, int k) {
  if (cache.count({P, k})) {
    return cache[{P, k}];
  }
  int TrackIndex = 0;
  int CurrentSum = 0;
  int n = W.size();
  for (int i = 0; i < n; i++) {
    if (W[i] > P) {
      return cache[{P, k}] = false;
    }
    if (CurrentSum + W[i] > P) {
      TrackIndex++;
      if (TrackIndex == k) {
        return cache[{P, k}] = false;
      }
      CurrentSum = 0;
    }
    CurrentSum += W[i];
  }
  return cache[{P, k}] = true;
}

int Calc(const vector<int>& W, int k) {
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