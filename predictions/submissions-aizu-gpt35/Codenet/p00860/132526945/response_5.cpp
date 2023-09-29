#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_H = 16;
const int MAX_W = 20;
const int MAX_STATES = 1 << 24;
const int MAX_DIFFS = 5;
const int MAX_ALPHABETS = 26;
const int MAX_POSITIONS = 8;
const int MAX_MOVES = 3;

unsigned short vis[MAX_STATES];
char c[MAX_H][MAX_W];
bool wall[MAX_H * MAX_W];
int tm0;

inline bool check(int u, int v) {
    for (int i = 0; i < MAX_POSITIONS; i += 2) {
        int p1 = (v >> i * 3) & 0xff;
        if (p1) {
            int j = (i + 2) % 8;
            if (wall[p1]) {
                return false;
            }
            int p2 = (v >> j * 3) & 0xff;
            if (p1 == p2) {
                return false;
            }
            if (p1 == ((u >> j * 3) & 0xff) && p2 == ((u >> i * 3) & 0xff)) {
                return false;
            }
        }
    }
    return true;
}

int solve(int start, int goal) {
    const int dif[MAX_MOVES] = {0, -1, 1, -MAX_W, MAX_W};
    queue<int> q;
    q.push(start);
    q.push(-1);
    int tm = tm0 + 1;
    vis[start] = tm;
    while (1) {
        int u = q.front();
        q.pop();
        if (u < 0) {
            q.push(-1);
            ++tm;
        } else {
            for (int i1 = (u & 0xff) ? MAX_MOVES : 0; i1 >= 0; --i1) {
                for (int i2 = ((u >> 8) & 0xff) ? MAX_MOVES : 0; i2 >= 0; --i2) {
                    for (int i3 = (u >> 16) ? MAX_MOVES : 0; i3 >= 0; --i3) {
                        int v = u + dif[i1] + (dif[i2] << 8) + (dif[i3] << 16);
                        if (vis[v] > tm0) {
                            continue;
                        }
                        if (check(u, v)) {
                            if (v == goal) {
                                return tm;
                            }
                            vis[v] = tm;
                            q.push(v);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int w, h;
    while (scanf("%d%d%*d", &w, &h), w) {
        memset(vis, 0, sizeof vis);
        memset(wall, false, sizeof wall);
        for (int i = 0; i < h; ++i) {
            scanf("%s", c[i]);
        }
        int goal = 0;
        int start = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (c[i][j] == '#') {
                    wall[i * MAX_W + j] = true;
                } else {
                    wall[i * MAX_W + j] = false;
                    if (isupper(c[i][j])) {
                        goal |= ((i * MAX_W + j) << ((c[i][j] - 'A') * 3));
                    } else if (islower(c[i][j])) {
                        start |= ((i * MAX_W + j) << ((c[i][j] - 'a') * 3));
                    }
                }
            }
        }
        int tm = solve(start, goal);
        printf("%d\n", tm - tm0);
        tm0 = tm;
    }
}
