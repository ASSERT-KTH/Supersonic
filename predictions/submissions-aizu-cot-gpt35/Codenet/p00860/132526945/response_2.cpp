#include <cstdio>
#include <cstring>
#include <deque>

bool wall[256];

inline bool check(int u, int v) {
  for (int i = 0; i < 24; i += 8) {
    int p1 = v >> i & 255;
    if (p1) {
      int j = i == 16 ? 0 : i + 8;
      if (wall[p1]) {
        return false;
      }
      int p2 = (v >> j % 24) & 255;
      if (p1 == p2) {
        return false;
      }
    }
  }
  return true;
}

int solve(int start, int goal) {
  const int dif[5] = {0, -1, 1, -16, 16};
  std::deque<int> q;
  q.push_back(start);
  q.push_back(-1);
  int tm = 1;
  int maxVisited = 0;
  
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    
    if (u < 0) {
      q.push_back(-1);
      ++tm;
    } else {
      for (int i1 = u & 255 ? 4 : 0; i1 >= 0; --i1)
        for (int i2 = u >> 8 & 255 ? 4 : 0; i2 >= 0; --i2)
          for (int i3 = u >> 16 ? 4 : 0; i3 >= 0; --i3) {
            int v = u + dif[i1] + (dif[i2] << 8) + (dif[i3] << 16);
            
            if (v > maxVisited) {
              maxVisited = v;
              if (maxVisited > 55000) {
                memset(wall, 0, sizeof wall);
                maxVisited = 0;
              }
            }
            
            if (v == goal) {
              return tm;
            }
            
            if (check(u, v)) {
              q.push_back(v);
            }
          }
    }
  }
  
  return -1; // Goal not reachable
}

int main() {
  int w, h;
  
  while (scanf("%d%d%*d ", &w, &h), w) {
    std::memset(wall, 0, sizeof wall);
    char c[16][20];
    
    for (int i = 0; i < h; ++i) {
      fgets(c[i], 20, stdin);
    }
    
    int goal = 0;
    int start = 0;
    
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (c[i][j] == '#') {
          wall[i << 4 | j] = true;
        } else {
          wall[i << 4 | j] = false;
          if (isupper(c[i][j])) {
            goal |= (i << 4 | j) << (c[i][j] - 'A') * 8;
          } else if (islower(c[i][j])) {
            start |= (i << 4 | j) << (c[i][j] - 'a') * 8;
          }
        }
      }
    }
    
    int tm = solve(start, goal);
    printf("%d\n", tm);
  }
}