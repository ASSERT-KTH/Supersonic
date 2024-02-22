#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
#include <unordered_set>
using namespace std;

char c[16][20];
bool wall[256];

struct State {
    int a, b, c;
};

inline bool check(int u, int v) {
    // New implementation...
}

int solve(int start, int goal, int tm0) {
    const int dif[5] = {0, -1, 1, -16, 16};
    queue<int> q;
    unordered_set<int> visited;
    
    q.push(start);
    q.push(-1);
    int tm = tm0 + 1;
    visited.insert(start);
    //...
}

int main() {
    int w, h;
    int tm0 = 0;
    while (scanf("%d%d%*d ", &w, &h), w) {
        for (int i = 0; i < h; ++i) {
            fgets(c[i], 20, stdin);
        }
        int goal = 0;
        int start = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                //...
            }
        }
        int tm = solve(start, goal, tm0);
        printf("%d\n", tm - tm0);
        tm0 = tm + 1;
        if (tm0 > 55000) {
            tm0 = 0;
        }
    }
}