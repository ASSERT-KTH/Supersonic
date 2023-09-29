#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Input(int n) {
  vector<int> W(n);
  for (int i = 0; i < n; i++) {
    cin >> W[i];
  }
  return W;
}

bool IsAllLoaded(int P, const vector<int>& W, int k) {
  int TrackIndex = 0;
  int CurrentSum = 0;

  for (const auto& w : W) {
    if (w > P) {
      return false;
    }
    if (CurrentSum + w > P) {
      TrackIndex++;
      if (TrackIndex == k) {
        return false;
      }
      CurrentSum = 0;
    }
    CurrentSum += w;
  }
  return true;
}

int Calc(vector<int>& W, int k) {
  int P = *max_element(W.begin(), W.end());
  int right = accumulate(W.begin(), W.end(), 0);
  while (P < right) {
    int mid = P + (right - P) / 2;
    if (IsAllLoaded(mid, W, k)) {
      right = mid;
    } else {
      P = mid + 1;
    }
  }
  return P;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> W = Input(n);
  int P = Calc(W, k);
  cout << P << '\n';
}