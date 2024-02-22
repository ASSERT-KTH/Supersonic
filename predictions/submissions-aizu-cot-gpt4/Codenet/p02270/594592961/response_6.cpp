#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
void Input(vector<int>& W, const int n) {
  W.reserve(n);
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    W.push_back(w);
  }
}
bool IsAllLoaded(int P, const vector<int>& W, int k) {
  int TrackIndex = 0;
  int CurrentSum = 0;
  int size = W.size();
  for (int i = 0; i < size; i++) {
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
int Calc(vector<int>& W, int k) {
  int Sum = accumulate(W.begin(), W.end(), 0);
  int P = (Sum + k - 1) / k;
  while (!IsAllLoaded(P, W, k)) {
    P++;
  }
  return P;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> W;
  Input(W, n);
  int P = Calc(W, k);
  cout << P << '\n';
  return 0;
}