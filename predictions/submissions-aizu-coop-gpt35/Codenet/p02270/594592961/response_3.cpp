#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int>& W, const int n) {
  for (int i = 0; i < n; i++) {
    cin >> W[i];
  }
}

bool IsAllLoaded(int P, const vector<int>& W, int k) {
  int TrackIndex = 0;
  int CurrentSum = W[0];
  int i = 1;
  while (i < W.size()) {
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
    i++;
  }
  return true;
}

int Calc(const vector<int>& W, int k) {
  int Sum = accumulate(W.begin(), W.end(), 0);
  int P = (Sum + k - 1) / k;
  auto it = lower_bound(W.begin(), W.end(), P);
  while (it != W.end() && !IsAllLoaded(*it, W, k)) {
    it++;
  }
  return *it;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> W(n);
  Input(W, n);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}