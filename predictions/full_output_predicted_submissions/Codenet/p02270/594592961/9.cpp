#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
vector<int> Input(const int n) {
  vector<int> W;
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    W.push_back(w);
  }
  return W;
}
bool IsAllLoaded(int P, vector<int> W, int k) {
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
    currentSum += W[i];
  }
  return true;
}
int Calc(vector<int> W, int k) {
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
  vector<int> W = Input(n);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}
