#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define M 9999
int parent[M];
int root(int a) { return parent[a] == a ? a : parent[a] = root(parent[a]); }
int unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y)
    return 0;
  parent[x] = y;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, n;
  double x, y, z, r;
  for (; scanf("%d", &n), n;) {
    vector<vector<double>> v;
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf%lf", &x, &y, &z, &r), v.push_back({x, y, z, r});
    for (i = 0; i < n; i++)
      parent[i] = i;
    double maxX = -1;
    int maxI, maxJ;
    for (i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        double radiusSum = v[i][3] + v[j][3];
        double distSq = 0;
        for (int k = 0; k < 3; k++)
          distSq += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
        if (distSq <= radiusSum * radiusSum)
          unite(i, j);
        else {
          double dist = sqrt(distSq) - radiusSum;
          if (dist > maxX) {
            maxX = dist;
            maxI = i;
            maxJ = j;
          }
        }
      }
    if (maxX > 0 && unite(maxI, maxJ))
        x += maxX;
    printf("%.3f\n", x);
  }
}