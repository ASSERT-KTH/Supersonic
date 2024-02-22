#include <iostream>
#include <vector>

std::vector<int> Input(const int n) {
  std::vector<int> W;
  W.reserve(n);
  for (int i = 0; i < n; ++i) {
    int w;
    std::cin >> w;
    W.push_back(w);
  }
}

bool IsAllLoaded(int P, const std::vector<int>& W, int k) {
  int trackIndex = 0;
  int currentSum = 0;
  for (int i = 0; i < W.size(); ++i) {
    if (W[i] > P) {
      return false;
    }
    if (currentSum + W[i] > P) {
      trackIndex++;
      if (trackIndex == k) {
        return false;
      }
      currentSum = 0;
    }
    currentSum += W[i];
  }
  return true;
}

int Calc(const std::vector<int>& W, int k) {
  int sum = std::accumulate(W.begin(), W.end(), 0);
  int P = (sum + k - 1) / k;
  while (!IsAllLoaded(P, W, k)) {
    P++;
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