#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x)                                                             \
  sort(x.begin(), x.end());                                                    \
  x.erase(unique(x.begin(), x.end()), x.end());
#define rep(i, n) for (int(i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int(i) = (m); (i) < (n); ++(i))
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y)                                                           \
  cerr << "(" << #x << ", " << #y << ") = "                                  \
       << "(" << x << ", " << y << ")" << endl;
#define debug3(x, y, z)                                               