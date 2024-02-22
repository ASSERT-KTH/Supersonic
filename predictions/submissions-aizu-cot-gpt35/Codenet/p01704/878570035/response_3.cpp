#include <iostream>
#include <limits>
#include <vector>

constexpr int MAXN = 100000 + 10;
constexpr double eps = 1e-7;

std::vector<int> vehicleWeight;
std::vector<int> productionCost;
std::vector<int> vehicleFactor;
std::vector<int> targetHours;

double calculateCost(double weight) {
  double cost = weight * pw;
  for (int i = 0; i < N; ++i) {
    double need = targetHours[i] - weight * vehicleWeight[i];
    if (need <= 0)
      continue;
    double factor = need / vehicleFactor[i];
    cost += factor * productionCost[i];
  }
  return cost;
}

int main() {
  int N, pw;
  while (std::cin >> N && N) {
    std::cin >> pw;
    vehicleWeight.resize(N);
    productionCost.resize(N);
    vehicleFactor.resize(N);
    targetHours.resize(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> vehicleWeight[i] >> productionCost[i] >> vehicleFactor[i] >>
          targetHours[i];
    }
    double left = 0, right = std::numeric_limits<double>::max();
    for (int _ = 0; _ < 200; ++_) {
      double mid = (left + right) / 2.0;
      double cost = calculateCost(mid);
      if (cost < calculateCost(mid + eps))
        right = mid;
      else
        left = mid;
    }
    std::cout << std::fixed << std::setprecision(10) << calculateCost(left)
              << "\n";
  }
  return 0;
}