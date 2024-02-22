#include <iostream>
#include <numeric>
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
  int P = *max_element(W.begin(), W.end()); // Initialize P with the maximum weight in W
  int Sum = accumulate(W.begin(), W.end(), 0);

  int lower = P; // Lower bound for binary search
  int upper = Sum; // Upper bound for binary search

  while (lower < upper) {
    int mid = lower + (upper - lower) / 2; // Calculate mid value

    if (IsAllLoaded(mid, W, k)) {
      upper = mid; // Update upper bound
    } else {
      lower = mid + 1; // Update lower bound
    }
  }

  return lower;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> W = Input(n);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}