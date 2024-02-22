#include <iostream>
#include <cmath>

using namespace std;

class Point3d {
public:
  double x, y, z;
  Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
};

bool point_on_the_triangle3d(Point3d tri1, Point3d tri2, Point3d tri3, Point3d p) {
  double dist1 = (tri2.y - tri1.y) * (p.z - tri1.z) - (tri2.z - tri1.z) * (p.y - tri1.y);
  double dist2 = (tri3.y - tri1.y) * (p.z - tri1.z) - (tri3.z - tri1.z) * (p.y - tri1.y);
  double dist3 = (tri1.y - tri3.y) * (p.z - tri3.z) - (tri1.z - tri3.z) * (p.y - tri3.y);
  double dot1 = dist1 * dist2;
  double dot2 = dist2 * dist3;
  if ((dot1 != 0.0 && dot1 > 0) && (dot2 != 0.0 && dot2 > 0)) {
    return true;
  }
  return false;
}

int main() {
  Point3d tri1, tri2, tri3, S, G;
  cin >> S.x >> S.y >> S.z;
  cin >> G.x >> G.y >> G.z;
  cin >> tri1.x >> tri1.y >> tri1.z;
  cin >> tri2.x >> tri2.y >> tri2.z;
  cin >> tri3.x >> tri3.y >> tri3.z;

  double dist1 = (tri2.y - tri1.y) * (tri3.z - tri1.z) - (tri2.z - tri1.z) * (tri3.y - tri1.y);
  double dist2 = (tri3.y - tri1.y) * (tri2.z - tri1.z) - (tri3.z - tri1.z) * (tri2.y - tri1.y);
  double dist3 = (tri1.y - tri3.y) * (tri2.z - tri1.z) - (tri1.z - tri3.z) * (tri2.y - tri1.y);
  double d = dist1 * tri1.x + dist2 * tri2.x + dist3 * tri3.x;

  double dist = (d - (dist1 * S.x + dist2 * S.y + dist3 * S.z)) /
                sqrt(dist1 * dist1 + dist2 * dist2 + dist3 * dist3);

  if (dist < 0) {
    cout << "HIT" << endl;
  } else {
    Point3d cp = S + (G - S) * (dist / sqrt((G.x - S.x) * (G.x - S.x) + (G.y - S.y) * (G.y - S.y) + (G.z - S.z) * (G.z - S.z)));
    if (point_on_the_triangle3d(tri1, tri2, tri3, cp)) {
      cout << "MISS" << endl;
    } else {
      cout << "HIT" << endl;
    }
  }

  return 0;
}