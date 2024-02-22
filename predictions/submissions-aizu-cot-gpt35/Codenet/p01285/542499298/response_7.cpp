#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Segment {
  Point p1, p2;
  int index;
  Segment(Point p1 = Point(), Point p2 = Point(), int index = -1)
      : p1(p1), p2(p2), index(index) {}
};

const string MANY = "Many";
const string NONE = "None";

void compute(const vector<Segment>& vec) {
  if (vec.size() <= 2) {
    cout << MANY << '\n';
    return;
  }
  vector<Segment> candidateLines;
  int n = vec.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((vec[i].p1.y - vec[i].p2.y) * (vec[j].p1.x - vec[j].p2.x) == 
          (vec[i].p1.x - vec[i].p2.x) * (vec[j].p1.y - vec[j].p2.y)) {
        double e_x = vec[i].p2.x - vec[i].p1.x;
        double e_y = vec[i].p2.y - vec[i].p1.y;
        double e_length = sqrt(e_x * e_x + e_y * e_y);
        double cp1_x = vec[i].p1.x + e_y / e_length * 100;
        double cp1_y = vec[i].p1.y - e_x / e_length * 100;
        double cp2_x = vec[i].p1.x - e_y / e_length * 100;
        double cp2_y = vec[i].p1.y + e_x / e_length * 100;
        double mp_x = (cp1_x + cp2_x) / 2.0;
        double mp_y = (cp1_y + cp2_y) / 2.0;
        double e1_x = vec[i].p2.x - vec[i].p1.x;
        double e1_y = vec[i].p2.y - vec[i].p1.y;
        double e1_length = sqrt(e1_x * e1_x + e1_y * e1_y);
        double e2_x = vec[j].p2.x - vec[j].p1.x;
        double e2_y = vec[j].p2.y - vec[j].p1.y;
        double e2_length = sqrt(e2_x * e2_x + e2_y * e2_y);
        double arg_a = M_PI - fabs(atan2(e1_y, e1_x) - atan2(e2_y, e2_x));
        double e_x_new = (e1_x / e1_length + e2_x / e2_length) / 2.0;
        double e_y_new = (e1_y / e1_length + e2_y / e2_length) / 2.0;
        double e_length_new = sqrt(e_x_new * e_x_new + e_y_new * e_y_new);
        double e1_new_x = e_x_new - e_y_new / e_length_new * tan(arg_a / 2.0);
        double e1_new_y = e_y_new + e_x_new / e_length_new * tan(arg_a / 2.0);
        double cp_x = mp_x + e1_new_x * 100;
        double cp_y = mp_y + e1_new_y * 100;