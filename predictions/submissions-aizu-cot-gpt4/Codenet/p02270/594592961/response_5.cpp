#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
void Input(const int n, vector<int> &W) {
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    W.push_back(w);
  }
}
bool IsAllLoaded(int P, const vector<int> &W, int k) {
  int TrackIndex = 0;
  int CurrentSum = 0;
  for (int i = 0; i < W.size(); i++) {
    if (W[i] > P) {
      return false;
    }
    if (CurrentSum + W[i] > P) {
      if (++TrackIndex == k) {
        return false;
      }
      CurrentSum = 0;
    } else {
      CurrentSum += W[i];
    }
  }
  return true;
}
int Calc(const vector<int> &W, int k) {
  int Sum = accumulate(W.begin(), W.end(), 0);
  int left = *max_element(W.begin(), W.end());
  int right = Sum;
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
  vector<int> W; 
  W.reserve(n);
  Input(n, W);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}