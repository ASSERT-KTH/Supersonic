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

  for (auto& weight : W) {
    if (weight > P) {
      return false;
    }
    if (CurrentSum + weight > P) {
      TrackIndex++;
      if (TrackIndex == k) {
        return false;
      }
      CurrentSum = weight;
    } else {
      CurrentSum += weight;
    }
  }
  return true;
}

int Calc(vector<int> W, int k) {
  int Sum = accumulate(W.begin(), W.end(), 0);
  int P = max((Sum + k - 1) / k, *max_element(W.begin(), W.end()));
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