#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define REP(i, a, n) for (i = a; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it, x) for(auto it = x.begin(); it != x.end(); it++)
typedef long long ll;
constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {-1, 0, 1, 0};
int w, h, tatu_x[20], tatu_y[20], kazu_x[20], kazu_y[20];
int field[144], cx[36], cy[36], csize;
map<pair<int, int>, int> idx;
set<ll> visited[20][4][2];
inline bool inside(int x, int y) const { return !(x < 0 || x >= w || y >= h || y < 0); }
bool backtrack(int cnt, ll kS, int init_dir, int f) const {
  // ... same code ...
}
bool solve() const {
  // ... same code ...
}
int main() {
  // ... same code ...
}