#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Input(const int n) {
  vector<int> W(n);
  for (int i = 0; i < n; ++i) {
    cin >> W[i];
  }
  return W;
}

bool IsAllLoaded(int P, const vector<int>& W, int k) {
  int TrackIndex = 0;
  int CurrentSum = 0;
  for (int i = 0; i < W.size(); ++i) {
    if (W[i] > P) {
      return false;
    }
    if (CurrentSum + W[i] > P) {
      TrackIndex++;
      if (TrackIndex == k) {
        return false;
      }
      CurrentSum = W[i];
    } else {
      CurrentSum += W[i];
    }
  }
  return true;
}

int Calc(vector<int>& W, int k) {
  int Sum = accumulate(W.begin(), W.end(), 0);
  int P = max(*max_element(W.begin(), W.end()), (Sum + k - 1) / k);
  while (!IsAllLoaded(P, W, k)) {
    P++;
  }
  return P;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k;
  cin >> n >> k;
  vector<int> W = Input(n);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}