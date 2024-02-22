#include <iostream>
#include <stack>
using namespace std;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int main() {
  int H, W;
  while (cin >> W >> H, H || W) {
    char** mp = new char*[H];
    for (int i = 0; i < H; ++i) {
      mp[i] = new char[W];
      for (int j = 0; j < W; ++j) {
        cin >> mp[i][j];
        if (mp[i][j] == '@')
          mp[i][j] = '.';
      }
    }

    int sy, sx;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (mp[i][j] == '.') {
          sy = i;
          sx = j;
          break;
        }
      }
    }

    stack<pair<int, int>> st;
    st.push(make_pair(sy, sx));
    mp[sy][sx] = ' ';
    int count = 0;

    while (!st.empty()) {
      int y = st.top().first;
      int x = st.top().second;
      st.pop();
      count++;

      for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < H && nx >= 0 && nx < W && mp[ny][nx] == '.') {
          st.push(make_pair(ny, nx));
          mp[ny][nx] = ' ';
        }
      }
    }

    cout << count << endl;

    for (int i = 0; i < H; ++i) {
      delete[] mp[i];
    }
    delete[] mp;
  }

  return 0;
}