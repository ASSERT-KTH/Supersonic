#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>

struct Item {
  int vw, pf, vf, th;
};

double calc(double W, const std::vector<Item>& items) {
  double cost = W * pw;
  for (const auto& item : items) {
    double need = item.th - W * item.vw;
    if (need > 0) {
      double f = need / item.vf;
      cost += f * item.pf;
    }
  }
  return cost;
}

int main() {
  int N, pw;
  while (scanf("%d", &N) == 1 && N) {
    scanf("%d", &pw);
    
    std::vector<Item> items(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", &items[i].vw, &items[i].pf, &items[i].vf, &items[i].th);
    }
    
    double left = 0, right = INT_MAX;
    for (int _ = 0; _ < 200; ++_) {
      double m1 = (left + left + right) / 3.0;
      double m2 = (left + right + right) / 3.0;
      double c1 = calc(m1, items);
      double c2 = calc(m2, items);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    
    printf("%.10f\n", calc(left, items));
  }
  return 0;
}