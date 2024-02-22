#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void Input(int n, vector<int>& W) {
  W.reserve(n);
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    W.push_back(w);
  }
}

bool IsAllLoaded(int P, vector<int>& W, int k) {
  int TrackIndex = 0;
  int CurrentSum = 0;
  for (int i = 0; i < W.size(); i++) {
    if (CurrentSum + W[i] > P) {
      if (W[i] > P || TrackIndex == k) {
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
  Input(n, W);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}