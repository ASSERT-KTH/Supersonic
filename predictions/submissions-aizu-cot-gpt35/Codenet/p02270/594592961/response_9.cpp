#include <iostream>
#include <vector>
using namespace std;

vector<int> Input(const int& n) {
  vector<int> W(n);
  for (int i = 0; i < n; i++) {
    cin >> W[i];
  }
  return W;
}

bool IsAllLoaded(int P, const vector<int>& W, int k) {
  int CurrentSum = 0;
  int remainingFiles = k;
  for (const int& w : W) {
    if (w > P) {
      return false;
    }
    if (CurrentSum + w > P) {
      remainingFiles--;
      if (remainingFiles == 0) {
        return false;
      }
      CurrentSum = 0;
    }
    CurrentSum += w;
  }
  return true;
}

int Calc(const vector<int>& W, int k) {
  int low = 1;
  int high = 1e9;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (IsAllLoaded(mid, W, k)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> W = Input(n);
  int P = Calc(W, k);
  cout << P << endl;
  return 0;
}