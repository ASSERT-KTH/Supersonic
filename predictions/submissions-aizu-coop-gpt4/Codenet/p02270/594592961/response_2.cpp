#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

// Now `W` is passed by reference
void Input(vector<int>& W, const int n) {
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    W.push_back(w);
  }
}

// Now `W` is passed by reference
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

// Now `W` is passed by reference
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
  std::ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> W;
  W.reserve(n);
  Input(W, n);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}