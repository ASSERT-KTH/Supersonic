#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

double EPS = 1e-6;

double add(double a, double b) {
  if (std::abs(a + b) < EPS * (std::abs(a) + std::abs(b)))
    return 0;
  return a + b;
}

struct point {
  double x, y;

  point() {}

  point(double x, double y) : x(x), y(y) {}

  point operator+(point p) {
    return point(add(x, p.x), add(y, p.y));
  }

  point operator-(point p) {
    return point(add(x, -p.x), add(y, -p.y));
  }

  point operator*(double d) {
    return point(x * d, y * d);
  }

  point operator/(double d) {
    return point(x / d, y / d);
  }
};

double dist(point a, point b) {
  return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

int main(void) {
  int n, x, y, v;
  std::vector<double> Px, Py, Vx, Vy, distances;
  
  while (std::cin >> n, n) {
    Px.clear();
    Py.clear();
    Vx.clear();
    Vy.clear();
    distances.clear();
    
    Px.reserve(n);
    Py.reserve(n);
    Vx.reserve(n);
    Vy.reserve(n);
    distances.resize(n);
    
    for (int i = 0; i < n; i++) {
      std::cin >> x >> y >> v;
      Px.push_back(x);
      Py.push_back(y);
      Vx.push_back(v);
      Vy.push_back(v);
      
      distances[i] = dist(point(x, y), point(0, 0));
    }
    
    double r = 0.98;
    point now(0, 0);
    double d = 10;
    
    while (d > EPS) {
      int mx = 0;
      double mxd = 0;
      
      #pragma omp simd
      for (int j = 0; j < n; j += 4) {
        double d0 = distances[j] / Vx[j];
        double d1 = distances[j + 1] / Vx[j + 1];
        double d2 = distances[j + 2] / Vx[j + 2];
        double d3 = distances[j + 3] / Vx[j + 3];
        
        if (d0 > mxd) {
          mx = j;
          mxd = d0;
        }
        
        if (d1 > mxd) {
          mx = j + 1;
          mxd = d1;
        }
        
        if (d2 > mxd) {
          mx = j + 2;
          mxd = d2;
        }
        
        if (d3 > mxd) {
          mx = j + 3;
          mxd = d3;
        }
      }
      
      now = now + ((point(Px[mx], Py[mx]) - now) / distances[mx] * d);
      d *= r;
    }
    
    double ans = 0;
    
    for (int i = 0; i < n; i++) {
      ans = std::max(ans, dist(now, point(Px[i], Py[i])) / Vx[i]);
    }
    
    std::printf("%.8f\n", ans);
  }
  
  return 0;
}