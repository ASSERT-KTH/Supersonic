#include <iostream>
#include <numeric>
#include <vector>

std::vector<int> Input(const int n) {
  std::vector<int> W;
  W.reserve(n);
  for (int i = 0; i < n; ++i) {
    int w;
    std::cin >> w;
    W.push_back(w);
  }
  return W;
}

bool IsAllLoaded(int P, const std::vector<int>& W, int k) {
  int TrackIndex = 0;
  int CurrentSum = 0;
  for (int i = 0; i < W.size(); ++i) {
    if (W[i] > P) {
      return false;
    }
    if (CurrentSum + W[i] > P) {
      ++TrackIndex;
      if (TrackIndex == k) {
        return false;
      }
      CurrentSum = 0;
    }
    CurrentSum += W[i];
  }
  return true;
}

int Calc(const std::vector<int>& W, int k) {
  int Sum = std::accumulate(W.begin(), W.end(), 0);
  int P = (Sum + k - 1) / k;
  while (!IsAllLoaded(P, W, k)) {
    ++P;
  }
  return P;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> W = Input(n);
  int P = Calc(W, k);
  std::cout << P << std::endl;
  return 0;
}