#include <iostream>
#include <cmath>

// Function to calculate the projection of point (cx, cy) onto the line segment formed by points (ax, ay) and (bx, by)
void project(double ax, double ay, double bx, double by, double cx, double cy) {
  double bx_ax = bx - ax;
  double by_ay = by - ay;
  double cx_ax = cx - ax;
  double cy_ay = cy - ay;
  
  double dot_product = cx_ax * bx_ax + cy_ay * by_ay;
  double length_squared = bx_ax * bx_ax + by_ay * by_ay;
  
  double projection_x = ax + (dot_product / length_squared) * bx_ax;
  double projection_y = ay + (dot_product / length_squared) * by_ay;
  
  std::cout << std::fixed << std::setprecision(8) << projection_x << " " << projection_y << std::endl;
}

int main() {
  double ax, ay, bx, by, cx, cy;
  int n;
  
  std::cin >> ax >> ay >> bx >> by >> n;
  
  while (n--) {
    std::cin >> cx >> cy;
    project(ax, ay, bx, by, cx, cy);
  }
  
  return 0;
}