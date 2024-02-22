#include <cstdio>
#include <stack>
#include <cstring>

#define MAX_H 20
#define MAX_W 20

char mp[MAX_H][MAX_W];
size_t H, W;

void dfs(int sy, int sx) {
  std::stack<std::pair<int, int>> st;
  st.push({sy, sx});

  while (!st.empty()) {
    int y = st.top().first;
    int x = st.top().second;
    st.pop();

    if (y < 0 || y >= H || x < 0 || x >= W || mp[y][x] == '#' || mp[y][x] == ' ')
      continue;

    mp[y][x] = ' ';

    st.push({y - 1, x});
    st.push({y + 1, x});
    st.push({y, x - 1});
    st.push({y, x + 1});
  }
}

int main() {
  char line[MAX_W + 2]; // Buffer for reading a line

  while (fgets(line, sizeof(line), stdin)) {
    sscanf(line, "%zu %zu", &W, &H);
    if (H == 0 && W == 0)
      break;

    int sy, sx;
    for (size_t i = 0; i < H; ++i) {
      fgets(line, sizeof(line), stdin);
      for (size_t j = 0; j < W; ++j) {
        mp[i][j] = line[j];
        if (mp[i][j] == '@')
          sy = i, sx = j, mp[i][j] = '.';
      }
    }
    
    dfs(sy, sx);

    int cnt = 0;
    for (size_t i = 0; i < H; ++i) {
      for (size_t j = 0; j < W; ++j) {
        if (mp[i][j] == ' ')
          ++cnt;
      }
    }

    printf("%d\n", cnt);
  }

  return 0;
}