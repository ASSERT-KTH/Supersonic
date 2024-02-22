#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int M[8][8];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve(int y, int x) {
  stack<pair<int, int>> st;
  st.push(make_pair(y, x));
  while (!st.empty()) {
    int y = st.top().first;
    int x = st.top().second;
    st.pop();
    M[y][x] = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= 3; j++) {
        int ny = y + dy[i] * j;
        int nx = x + dx[i] * j;
        if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8) {
          if (M[ny][nx] == 1) {
            st.push(make_pair(ny, nx));
          }
        }
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 8; j++) {
      string s;
      cin >> s;
      for (int k = 0; k < 8; k++) {
        M[j][k] = s[k] - '0';
      }
    }
    int x, y;
    cin >> x >> y;
    solve(y - 1, x - 1);
    cout << "Data " << i + 1 << ":" << endl;
    for (int j = 0; j < 8; j += 2) {
      for (int k = 0; k < 8; k += 2) {
        cout << M[j][k] << M[j][k + 1] << M[j + 1][k] << M[j + 1][k + 1];
      }
      cout << endl;
    }
  }
  return 0;
}