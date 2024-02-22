#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

vector<int> Input(const int n) {
  vector<int> W;
  W.reserve(n);  // Reserve memory for n elements
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    W.push_back(w);
  }
  return W;
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

int Calc(const vector<int>& W, int k) {
  int Sum = accumulate(W.begin(), W.end(), 0);
  int Max = *max_element(W.begin(), W.end());
  int Left = max(Sum / k, Max), Right = Sum;
  while (Left < Right) {
    int Mid = Left + (Right - Left) / 2;
    if (IsAllLoaded(Mid, W, k)) {
      Right = Mid;
    } else {
      Left = Mid + 1;
    }
  }
  return Left;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> W = Input(n);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}