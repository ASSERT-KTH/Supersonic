#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
  long long x;
  long long y;
};

int main() {
  long long sum = 0LL, osum = 0LL;
  long long f1, f2, f3, w, h, L, HL, temp, ox, oy, max = 0, dx, dy;

  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);

  // Using fixed-size arrays for coordinates
  Point* points = new Point[L];

  for (f1 = 0; f1 < L; f1++) {
    scanf("%lld %lld", &points[f1].x, &points[f1].y);
  }

  // Sorting the combined coordinates
  sort(points, points + L, [](const Point& a, const Point& b) {
    return a.x < b.x;
  });

  HL = (L + 1) / 2;

  if (L == 1) {
    printf("0\n");
    printf("%lld %lld\n", points[0].x, points[0].y);
  } else {
    Point target;
    target.x = points[HL - 1].x;
    target.y = points[HL - 1].y;

    dx = (points[HL].x == target.x) ? 1 : 2;
    dy = (points[HL].y == target.y) ? 1 : 2;

    for (f2 = 0; f2 < dx; f2++) {
      for (f3 = 0; f3 < dy; f3++) {
        sum = 0LL;
        max = 0LL;

        for (f1 = 0; f1 < L; f1++) {
          temp = (long long)abs(points[f1].x - target.x) +
                 abs(points[f1].y - target.y);
          sum += temp;
          if (max < temp)
            max = temp;
        }

        sum *= 2;
        sum -= max;

        if (osum == 0 || osum > sum) {
          osum = sum;
          ox = target.x;
          oy = target.y;
        }
      }
    }

    printf("%lld\n", osum);
    printf("%lld %lld\n", ox, oy);
  }

  delete[] points;
  return 0;
}