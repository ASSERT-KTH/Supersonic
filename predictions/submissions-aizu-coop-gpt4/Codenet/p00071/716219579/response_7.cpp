#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;
int n;
int y, x, M[9][9];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve(int y, int x) {
  queue<P> q;
  q.push(P(y, x));
  while(!q.empty()) {
    P p = q.front(); q.pop();
    M[p.first][p.second] = 0;
    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i], nx = p.second + dx[i];
      if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1)
        q.push(P(ny, nx));
    }
  }
}

int main() {
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<8; j++)
      for(int k=0; k<8; k++)
        cin >> M[j][k];
    cin >> x >> y;
    solve(y - 1, x - 1);
    cout << "Data " << i + 1 << ":" << endl;
    for(int j=0; j<8; j++) {
      for(int k=0; k<8; k++)
        cout << M[j][k];
      cout << endl;
    }
  }
  return 0;
}