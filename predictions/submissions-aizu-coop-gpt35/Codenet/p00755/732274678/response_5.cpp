#include <iostream>
#include <stack>
#include <cstring>

int w, h, Col;
const int MAX_SIZE = 8;
int grid[MAX_SIZE * MAX_SIZE];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int res;

void calc(int y, int x) {
  std::stack<int> stack;
  stack.push(y * w + x);
  int count = 0;

  while (!stack.empty()) {
    int idx = stack.top();
    stack.pop();
    int cy = idx / w;
    int cx = idx % w;

    if (cy < 0 || cx < 0 || cx >= w || cy >= h || grid[idx] != Col) {
      continue;
    }

    count++;
    grid[idx] = 0;

    for (int r = 0; r < 4; r++) {
      int ny = cy + dy[r];
      int nx = cx + dx[r];
      int nidx = ny * w + nx;

      if (ny >= 0 && nx >= 0 && ny < h && nx < w && grid[nidx] == Col) {
        stack.push(nidx);
      }
    }
  }

  res = std::max(res, count);
}

void on(int count, int c) {
  if (count == 5) {
    int temp[MAX_SIZE * MAX_SIZE];
    std::memcpy(temp, grid, sizeof(grid));
    int tres = 0;
    calc(0, 0);
    res = std::max(res, res);
    std::memcpy(grid, temp, sizeof(grid));
    return;
  }

  int nc = grid[0];
  std::stack<int> stack;
  stack.push(0);
  bool used[MAX_SIZE * MAX_SIZE];
  std::memset(used, false, sizeof(used));

  while (!stack.empty()) {
    int idx = stack.top();
    stack.pop();

    if (used[idx]) {
      continue;
    }

    used[idx] = true;
    grid[idx] = c;

    int cy = idx / w;
    int cx = idx % w;

    for (int r = 0; r < 4; r++) {
      int ny = cy + dy[r];
      int nx = cx + dx[r];
      int nidx = ny * w + nx;

      if (ny >= 0 && nx >= 0 && ny < h && nx < w && grid[nidx] == nc) {
        stack.push(nidx);
      }
    }
  }

  for (int i = 1; i <= 6; i++) {
    on(count + 1, (count != 4) ? i : Col);
  }
}

void solve() {
  res = 0;
  for (int i = 0; i < h * w; i++) {
    std::cin >> grid[i];
  }

  for (int i = 1; i <= 6; i++) {
    if (grid[0] != i) {
      on(0, i);
    }
  }

  std::cout << res << std::endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  while (std::cin >> h >> w >> Col) {
    if (w == 0) {
      break;
    }
    solve();
  }

  return 0;
}