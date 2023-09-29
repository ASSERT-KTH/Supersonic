#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
typedef double D;
typedef complex<D> P;
typedef vector<P> VP;
typedef vector<VP> Vcon;
const D EPS = 1e-7;
#define X real()
#define Y imag()
#define EQ(n, m) (abs((n) - (m)) < EPS)
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define cross(a, b) (conj(a) * b).Y
#define dot(a, b) (conj(a) * b).X
#define ccw(a, b, c) (cross(b - a, c - a) > EPS ? 1 : cross(b - a, c - a) < -EPS ? -1 : dot(b - a, c - a) < -EPS ? 2 : norm(b - a) < norm(c - a) ? -2 : 0)
#define inPolygon(ps, p) ([&](){int n = ps.size(), ret = 0; for(int i = 0; i < n; i++){ if(EQ(cross(ps[i]-p, ps[(i+1)%n]-p), 0) && dot(ps[i]-p, ps[(i+1)%n]-p) <= 0) return 2; P a = ps[i] - p, b = ps[(i+1)%n] - p; if(a.Y > b.Y) swap(a, b); if(a.Y <= 0 && 0 < b.Y && cross(a, b) < 0) ret = !ret;} return ret;}())
#define convexCut(ps, a1, a2) ([&](){VP ret; int n = ps.size(); for(int i = 0; i < n; i++){ int ccwc = ccw(a1, a2, ps[i]), ccwn = ccw(a1, a2, ps[(i + 1)%n]); if(ccwc != -1) ret.push_back(ps[i]); if(ccwc * ccwn == -1) ret.push_back((a2 - a1) * dot(a2 - a1, ps[i] - a1) / dot(a2 - a1, ps[(i + 1)%n] - a1) + a1);} return ret;}())
#define divide_convex(ps, s1, s2, V) ([&](){for(int i = 0; i < s1.size(); i++){ VP cv1 = convexCut(ps, s1[i], s2[i]), cv2 = convexCut(ps, s2[i], s1[i]); if(cv1.size() > 2 && cv2.size() > 2){ divide_convex(cv1, s1, s2, V); return divide_convex(cv2, s1, s2, V);} } V.push_back(ps);}())
#define isecCC(a1, a2) ([&](){for(auto& e1 : a1) for(auto& e3 : a2) for(auto& e2 : a1) for(auto& e4 : a2) if(abs(e1 - e3) < EPS && abs(e2 - e4) < EPS || abs(e1 - e4) < EPS && abs(e2 - e3) < EPS) return true; return false;}())
#define con_in_con(a1, a2) ([&](){for(auto& j : a2){ int sum = 0, f = 0; for(auto& i : a1){ if(isecSP(i, a1[(i + 1) % a1.size()], j)) goto L1; if(isecSS(i, a1[(i + 1) % a1.size()], j, {1000007, 41321})){ sum++; f++;}} if(sum % 2) return true; L1: sum = f = 0; for(auto& i : a1){ if(isecSP(i, a1[(i + 1) % a1.size()], (j + a2[(j + 1) % a2.size()]) / 2.0)) goto L; if(isecSS(i, a1[(i + 1) % a1.size()], (j + a2[(j + 1) % a2.size()]) / 2.0, {1000007, 41321})){ sum++; f++;}} if(sum % 2) return true; L: ;} return false;}())
#define isecSP(a1, a2, b) (abs(a1 - b) + abs(a2 - b) - abs(a2 - a1) < EPS)
#define isecSS(a1, a2, b1, b2) (ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0)
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n;
  VP V[n], s1, s2;
  for(int i = 0; i < n; i++){
    cin >> m;
    D x[m], y[m];
    for(int j = 0; j < m; j++){ cin >> x[j] >> y[j]; V[i].push_back(P(x[j], y[j])); }
    for(int j = 0; j < m; j++){ s1.push_back(P(x[j], y[j])); s2.push_back(P(x[(j + 1) % m], y[(j + 1) % m])); }
  }
  VP convex = {{-200000, -200000}, {200000, -200000}, {200000, 200000}, {-200000, 200000}};
  Vcon v;
  divide_convex(convex, s1, s2, v);
  vector<vector<int>> a(v.size(), vector<int>(v.size(), 1e8));
  vector<int> cnt(v.size());
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < n; j++) if(con_in_con(V[j], v[i])) cnt[i]++;
    for(int j = 0; j < v.size(); j++){ if(i == j) a[i][j] = 0; else if(isecCC(v[i], v[j])) a[i][j] = a[j][i] = abs(cnt[i] - cnt[j]); }
  }
  for(int k = 0; k < v.size(); k++) for(int i = 0; i < v.size(); i++) for(int j = 0; j < v.size(); j++) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
  cin >> q;
  while(q--){
    int A = 1e9, B = 1e9;
    D a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    for(int i = 0; i < v.size(); i++){ if(inPolygon(v[i], {a1, a2})) A = i; if(inPolygon(v[i], {b1, b2})) B = i; }
    cout << a[A][B] << "\n";
  }
}