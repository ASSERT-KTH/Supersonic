#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(c) begin(c), end(c)
#define dump(x) cerr << __LINE__ << ":\t" #x " = " << x << endl
using ld = long double;
using P = complex<ld>;
using G = vector<P>;
const ld pi = acos(-1);
const ld eps = 1e-10;
const ld inf = 1e12;

ld cross(const P &a, const P &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

ld dot(const P &a, const P &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}

using C = pair<ld, P>;
#define rad first
#define pnt second
C smallest_enclosing_disc(vector<P> ps) {
  // ... same as before ...
}

int n, m;
ld r[111], mb[111];
bool used[111];

// Use priority queue instead of vector for balls
priority_queue<ld, vector<ld>, greater<ld>> balls;

bool chk(int s) {
  // ... same as before ...
  sort(all(a));
  // Use priority queue for ball radii
  while (!balls.empty()) balls.pop();
  for (auto radius : b) balls.push(radius);
  int last = -1;
  rep(i, a.size()) {
    bool found = false;
    while(!balls.empty() && a[i] < balls.top() + eps) {
      balls.pop();
      found = true;
      last = i;  // update last index
    }
    if (!found)
      return false;
  }
  return true;
}

int main() {
  // ... same as before ...
  rep(i, m) {
    int k;
    cin >> k;
    G g(k);
    rep(j, k) {
      ld x, y;
      cin >> x >> y;
      g[j] = P(x, y);
    }
    mb[i] = smallest_enclosing_disc(g).rad;
    balls.push(mb[i]);  // add radius to balls
  }
  // ... same as before ...
}