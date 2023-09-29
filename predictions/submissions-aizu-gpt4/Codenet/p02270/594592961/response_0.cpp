#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
vector<int> Input(const int n) {
  vector<int> W(n);
  for (auto& w : W) {
    cin >> w;
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
    else {
      CurrentSum += w;
    }
  }
  return true;
}
int Calc(const vector<int>& W, int k) {
  int Sum = accumulate(W.begin(), W.end(), 0);
  int P = (Sum + k - 1) / k;
  while (!IsAllLoaded(P, W, k)) {
    P++;
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
  cout << P << endl;
  return 0;
}