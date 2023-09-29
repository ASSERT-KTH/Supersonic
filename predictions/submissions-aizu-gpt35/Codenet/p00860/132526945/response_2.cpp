#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
#include <bitset>
using namespace std;

// Define constants
const int MAX_H = 16;
const int MAX_W = 16;
const int MAX_KEYS = 6;
const int MAX_STATES = (1 << MAX_KEYS) * MAX_H * MAX_W;

// Define global variables
int w, h;
char c[MAX_H][MAX_W + 1];
bitset<256> wall;
int tm0;
int keys[MAX_KEYS];
int num_keys;
int goal_pos[26];
int num_goals;
unsigned short vis[MAX_STATES];

// Define helper functions
inline int pos(int x, int y) {
  return x + y * w;
}

inline int add_key(int state, int key) {
  return state | (1 << key);
}

inline bool has_key(int state, int key) {
  return state & (1 << key);
}

inline bool check(int state, int pos) {
  if (wall[pos]) {
    return false;
  }
  if (state == 0) {
    return true;
  }
  int pkey = state & 63;
  if (pkey != 0) {
    if ((keys[pkey] & 1) && pos == goal_pos[pkey]) {
      return true;
    }
  }
  return !((state >> (c[pos / w][pos % w] - 'a' + 1 + MAX_KEYS) & 1) == 0);
}

// Define main algorithm function
int solve(int start) {
  // Define constants
  const int dif[5] = {0, -1, 1, -w, w};
  const int max_state = (1 << num_keys) * h * w;

  // Initialize variables
  queue<int> q;
  memset(vis, 0, sizeof vis);
  q.push(start);
  q.push(-1);
  int tm = tm0 + 1;
  vis[start] = tm;

  // Loop through the states
  while (true) {
    int u = q.front();
    q.pop();
    if (u < 0) {
      q.push(-1);
      ++tm;
    } else {
      int x = u % w;
      int y = u / w % h;
      int state = u / (w * h);
      if (state == ((1 << num_keys) - 1)) {
        return tm;
      }
      for (int i = 0; i < 5; ++i) {
        int nx = x + dif[i] % w;
        int ny = y + dif[i] / w;
        if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
          continue;
        }
        int v = pos(nx, ny);
        if (check(state, v)) {
          int nstate = state;
          int pkey = state & 63;
          if (c[ny][nx] >= 'a' && c[ny][nx] <= 'z') {
            int key = c[ny][nx] - 'a' + 1;
            nstate = add_key(state, key);
            keys[key] |= 1;
          } else if (c[ny][nx] >= 'A' && c[ny][nx] <= 'Z') {
            if (has_key(state, c[ny][nx] - 'A' + 1)) {
              nstate = state;
            } else {
              continue;
            }
          }
          if ((nstate & 63) != pkey) {
            keys[pkey] |= 2;
          }
          int nv = nstate * (w * h) + v;
          if (vis[nv] > tm0) {
            continue;
          }
          vis[nv] = tm;
          q.push(nv);
        }
      }
    }
  }
}

// Define main function
int main() {
  // Loop through the test cases
  while (scanf("%d%d%*d ", &w, &h), w) {
    // Read input
    memset(wall, false, sizeof wall);
    memset(keys, 0, sizeof keys);
    num_keys = 0;
    memset(goal_pos, 0, sizeof goal_pos);
    num_goals = 0;
    for (int i = 0; i < h; ++i) {
      fgets(c[i], MAX_W + 1, stdin);
      for (int j = 0; j < w; ++j) {
        int p = pos(j, i);
        if (c[i][j] == '#') {
          wall[p] = true;
        } else if (c[i][j] >= 'a' && c[i][j] <= 'z') {
          int key = c[i][j] - 'a' + 1;
          if (keys[key] == 0) {
            keys[key] = -1;
            num_keys++;
          }
        } else if (c[i][j] >= 'A' && c[i][j] <= 'Z') {
          int goal = c[i][j] - 'A' + 1;
          goal_pos[goal] = p;
          num_goals++;
        }
      }
    }

    // Initialize variables
    int start = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (c[i][j] == '@') {
          start = pos(j, i);
        }
      }
    }

    // Solve the problem
    int tm = solve(start);
    printf("%d\n", tm - tm0);
    tm0 = tm + 1;
    if (tm0 > 55000) {
      memset(vis, 0, sizeof vis);
      tm0 = 0;
    }
  }

  // Exit
  return 0;
}