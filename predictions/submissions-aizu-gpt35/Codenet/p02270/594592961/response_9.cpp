#include <iostream>
#include <vector>
using namespace std;

vector<int> Input(const int n) {
  vector<int> W(n);
  for (int i = 0; i < n; ++i) {
    cin >> W[i];
  }
  return W;
}

bool IsAllLoaded(int P, const vector<int>& W, const int k) {
  int CurrentSum = 0;
  for (int i = 0; i < W.size(); ++i) {
    if (W[i] > P) {
      return false;
    }
    if (CurrentSum + W[i] > P) {
      CurrentSum = 0;
      --k;
      if (k == 0) {
        return false;
      }
    }
    CurrentSum += W[i];
  }
  return true;
}

int Calc(const vector<int>& W, const int k) {
  int lo = 1;
  int hi = 1e9;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (IsAllLoaded(mid, W, k)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> W = Input(n);

  cout << Calc(W, k) << "\n";
  return 0;
}