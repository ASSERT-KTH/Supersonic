#include <cstdio>
#include <stack>
using namespace std;

#define rep(i, x) for (int i = 0; i < (int)(x); ++i)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

char mp[440];
bool visited[440];
int H, W;

void dfs(int y, int x) {
    stack<pair<int, int>> stk;
    stk.push({y, x});

    while (!stk.empty()) {
        auto [y, x] = stk.top(); stk.pop();
        if (y < 0 || y >= H || x < 0 || x >= W || mp[y*W+x] == '#' || visited[y*W+x])
            continue;
        visited[y*W+x] = true;

        rep(i, 4) stk.push({y + dy[i], x + dx[i]});
    }
}

int main() {
    while (scanf("%d %d", &W, &H), H || W) {
        int sy, sx;
        fill(visited, visited+440, false);

        rep(i, H) rep(j, W) {
            scanf("\n%c", &mp[i*W+j]);
            if (mp[i*W+j] == '@')
                sy = i, sx = j, mp[i*W+j] = '.';
        }

        dfs(sy, sx);

        int cnt = count(visited, visited+440, true);
        printf("%d\n", cnt);
    }
}