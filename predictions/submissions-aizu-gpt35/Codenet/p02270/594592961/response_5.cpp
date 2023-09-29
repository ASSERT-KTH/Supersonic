#include <iostream>
#include <vector>
using namespace std;

// Function to take input and return a vector of integers
vector<int> Input(const int n) {
  vector<int> W(n);
  for (int i = 0; i < n; i++) {
    cin >> W[i];
  }
  return W;
}

// Function to check if all the packets can be loaded with given max weight
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

// Function to calculate the minimum possible maximum weight
int Calc(const vector<int>& W, int k) {
  int Sum = 0;
  int MaxWt = 0;
  for (const auto& i : W) {
    Sum += i;
    MaxWt = max(MaxWt, i);
  }
  int l = MaxWt;
  int r = Sum;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (IsAllLoaded(mid, W, k)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return r;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> W = Input(n);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}