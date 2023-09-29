#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define INF 1e9
using namespace std;

inline void fastInput(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, l, k, a, h, t1, t2, t3;
  while (fastInput(n), fastInput(m), fastInput(l), fastInput(k), fastInput(a), fastInput(h), n) {
    set<int> rei;
    rei.insert(a), rei.insert(h);
    vector<vector<int>> b(n, vector<int>(n, INF));
    vector<vector<int>> x(n, vector<int>(n, INF));
    int re;
    for(int i=0;i<l;++i) {
      fastInput(re), rei.insert(re);
    }
    for(int i=0;i<k;++i) {
      fastInput(t1), fastInput(t2), fastInput(t3), b[t1][t2] = b[t2][t1] = t3;
    }
    for(int o=0;o<n;++o) for(int i=0;i<n;++i) for(int j=0;j<n;++j) b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
    for(int i=0;i<n;++i) if (rei.count(i)) for(int j=0;j<n;++j) if (rei.count(j)) if (b[i][j] <= m)
        x[i][j] = b[i][j];
    for(int o=0;o<n;++o) for(int i=0;i<n;++i) for(int j=0;j<n;++j) x[i][j] = min(x[i][j], x[i][o] + x[o][j]);
    if (x[a][h] >= INF)
      cout << "Help!" << '\n';
    else if (x[a][h] < m)
      cout << x[a][h] << '\n';
    else
      cout << x[a][h] * 2 - m << '\n';
  }
}