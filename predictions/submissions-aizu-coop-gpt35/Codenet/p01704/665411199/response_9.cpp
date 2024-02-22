#include <iostream>
#include <vector>
using namespace std;

struct Item {
  int vw, pf, vf, th;
};

int n, pw;
vector<Item> items;

int f(int W) {
  int cost = W * pw;
  for (int i = 0; i < n; i++) {
    if (W * items[i].vw > items[i].th)
      continue;
    int sum1 = items[i].th - W * items[i].vw;
    int sum2 = sum1 / items[i].vf;
    cost += sum2 * items[i].pf;
  }
  return cost;
}

int findMinCost(int l, int r) {
  while (l < r) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    int res1 = f(m1);
    int res2 = f(m2);
    if (res1 < res2)
      r = m2 - 1;
    else
      l = m1 + 1;
  }
  return f(l);
}

int main() {
  while (1) {
    cin >> n >> pw;
    if (n == 0)
      break;
    items.resize(n);
    for (int i = 0; i < n; i++)
      cin >> items[i].vw >> items[i].pf >> items[i].vf >> items[i].th;
    int l = 0, r = 1000000;
    int minCost = findMinCost(l, r);
    printf("%.4f\n", minCost / 10000.0);
  }
  return 0;
}