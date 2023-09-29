#include <cstdio>
#include <vector>
#define EPS 1e-10
#define F first
#define S second
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
using namespace std;
struct P {
  double x, y;
  P(double x = 0, double y = 0) : x(x), y(y) {}
  P operator+(P p) { return P(x + p.x, y + p.y); }
  P operator-(P p) { return P(x - p.x, y - p.y); }
  P operator*(P p) { return P(x * p.x, y * p.y); }
  P operator/(P p) { return P(x / p.x, y / p.y); }
  bool operator==(const P &p) const {
    return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
  }
  bool operator<(const P &p) const {
    return x != p.x ? fabs(x - p.x) < EPS : fabs(y - p.y) < EPS;
  }
};
typedef pair<P, P> Segment;
double dot(P a, P b) { return a.x * b.x + a.y * b.y; }
double cross(P a, P b) { return a.x * b.y - a.y * b.x; }
double norm(P p) { return p.x * p.x + p.y * p.y; }
double abs(P p) { return sqrt(norm(p)); }
int ccw(P p, P q, P r) {
  P a = q - p;
  P b = r - p;
  if (cross(a, b) > EPS)
    return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS)
    return CLOCKWISE;
  if (dot(a, b) < -EPS)
    return ONLINE_BACK;
  if (norm(a) < norm(b))
    return ONLINE_FRONT;
  return ON_SEGMENT;
}
bool isIntersect(P p1, P p2, P p3, P p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
P crosspoint(P p1, P p2, P p3, P p4) {
  double A = cross(p2 - p1, p4 - p3);
  double B = cross(p2 - p1, p2 - p3);
  P pro = p4 - p3;
  pro.x = pro.x * (B / A);
  pro.y = pro.y * (B / A);
  return p3 + pro;
}
int main() {
  int n, xx, yy, xxx, yyy, field;
  vector<Segment> pos;
  Segment pesh;
  vector<P> exist;
  P xp;
  while (cin >> n && n) {
    field = 1;
    pos.clear();
    for (int i = 0; i < n; i++) {
      cin >> xx >> yy >> xxx >> yyy;
      pesh.F.x = xx;
      pesh.F.y = yy;
      pesh.S.x = xxx;
      pesh.S.y = yyy;
      pos.push_back(pesh);
      int x_counter = 0;
      bool new_x = true;
      exist.clear();
      for (int i = 0; i < pos.size() - 1; i++) {
        new_x = true;
        if (isIntersect(pos[i].F, pos[i].S, pos[pos.size() - 1].F,
                        pos[pos.size() - 1].S)) {
          xp = crosspoint(pos[i].F, pos[i].S, pos[pos.size() - 1].F,
                          pos[pos.size() - 1].S);
          if (100 - fabs(xp.x) < EPS || 100 - fabs(xp.y) < EPS)
            continue;
          for (int j = 0; j < exist.size(); j++) {
            if (exist[j] == xp) {
              new_x = false;
              break;
            }
          }
          if (new_x) {
            x_counter++;
            exist.push_back(xp);
          }
        }
      }
      field += x_counter + 1;
    }
    cout << field << endl;
  }
  return 0;
}
