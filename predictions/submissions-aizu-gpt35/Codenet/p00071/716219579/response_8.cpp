#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, N) for (int i = 0; i < (N); i++)
#define ALL(s) (s).begin(), (s).end()

typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n;
int y, x, M[8][8];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve(int y, int x) {
  M[y][x] = 0;
  queue<pii> q;
  q.push({y, x});

  while (!q.empty()) {
    pii cur = q.front();
    q.pop();

    REP(i, 4) {
      FOR(j, 1, 4) {
        int ny = cur.first + dy[i] * j, nx = cur.second + dx[i] * j;
        if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8) {
          if (M[ny][nx] == 1) {
            M[ny][nx] = 0;
            q.push({ny, nx});
          }
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  REP(test_case, n) {
    REP(i, 8) {
      REP(j, 8) {
        char c;
        cin >> c;
        M[i][j] = c - '0';
      }
    }
    cin >> x >> y;
    solve(y - 1, x - 1);
    cout << "Data " << test_case + 1 << ":" << endl;
    REP(i, 8) {
      REP(j, 8) {
        cout << M[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}