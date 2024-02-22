#include <iostream>
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
  for (const int w : W) {
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
    CurrentSum += w;
  }
  return true;
}

int Calc(const vector<int>& W, int k) {
  int Sum = 0;
  int MaxElement = 0;
  for (const int w : W) {
    Sum += w;
    MaxElement = max(MaxElement, w);
  }
  int P = max(Sum / k, MaxElement);
  while (!IsAllLoaded(P, W, k)) {
    P += MaxElement;
  }
  return P;
}

int main() {
  int n, k, P;
  cin >> n >> k;
  vector<int> W = Input(n);
  P = Calc(W, k);
  cout << P << endl;
  return 0;
}