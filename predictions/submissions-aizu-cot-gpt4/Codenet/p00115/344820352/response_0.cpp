#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#define EPS (1e-7)
using namespace std;

inline bool equals(double a, double b) { return fabs((a) - (b)) < EPS; }
void rep(int i, int n) { for (i = 0; i < n; i++); }

// Rest of the code remains the same

int main() {
  Point3d tri[3], S, G;
  scanf("%lf %lf %lf", &S.x, &S.y, &S.z);
  scanf("%lf %lf %lf", &G.x, &G.y, &G.z);
  for(int i=0; i<3; i++) scanf("%lf %lf %lf", &tri[i].x, &tri[i].y, &tri[i].z);
  
  Plane3d plane(tri[0], tri[1], tri[2]);
  Segment3d seg(S, G);
  if (!plane.intersectS(seg)) {
    printf("%s\n", Y.c_str());
    return 0;
  }
  Point3d cp = plane.crosspointS(seg);
  printf("%s\n", (point_on_the_triangle3d(tri[0], tri[1], tri[2], cp) ? N.c_str() : Y.c_str()));
  return 0;
}