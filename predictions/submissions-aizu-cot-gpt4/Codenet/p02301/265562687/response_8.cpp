#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define PI 3.141592653589793238
#define int long long
using namespace std;
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
//... Rest of the structures and functions

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  scanf("%lld", &n); 

  Polygon p(n);
  for (int i = 0; i < n; i++)
    scanf("%lf %lf", &p[i].x, &p[i].y);

  printf("%.12f\n", diameter(p));
  return 0;
}