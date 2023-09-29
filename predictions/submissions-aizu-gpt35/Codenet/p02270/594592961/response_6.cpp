#include <iostream>
#include <algorithm>
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
  int CurrentSum = 0;
  for (const auto& w : W) {
    if (w > P) {
      return false;
    }
    CurrentSum += w;
    if (CurrentSum > P) {
      CurrentSum = w;
      if (--k == 0) {
        return false;
      }
    }
  }
  return true;
}

int Calc(const vector<int>& W, int k) {
  int l = *max_element(W.begin(), W.end());
  int r = accumulate(W.begin(), W.end(), 0);
  while (l < r) {
    int mid = (l + r) / 2;
    if (IsAllLoaded(mid, W, k)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> W = Input(n);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}