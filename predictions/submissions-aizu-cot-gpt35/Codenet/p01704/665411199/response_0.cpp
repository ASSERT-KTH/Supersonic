#include <iostream>
#include <iomanip>
#include <vector>

struct Item {
  double vw, pf, vf, th;
};

double f(double W, const std::vector<Item>& items) {
  double cost = W;
  for (const auto& item : items) {
    if (W * item.vw > item.th)
      continue;
    double sum1 = item.th - W * item.vw;
    double sum2 = sum1 / item.vf;
    cost += sum2 * item.pf;
  }
  return cost;
}

int main() {
  while (true) {
    int n;
    std::cin >> n;
    if (n == 0)
      break;
    std::vector<Item> items(n);
    for (int i = 0; i < n; i++)
      std::cin >> items[i].vw >> items[i].pf >> items[i].vf >> items[i].th;
    double l = 0, r = 1.0 / 0.0; // infinity
    for (int i = 0; i < 200; i++) {
      double m1 = (l * 2.0 + r) * (1.0 / 3.0);
      double m2 = (l + r * 2.0) * (1.0 / 3.0);
      double res1 = f(m1, items);
      double res2 = f(m2, items);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
    }
    std::cout << std::fixed << std::setprecision(4) << f(l, items) << std::endl;
  }
  return 0;
}