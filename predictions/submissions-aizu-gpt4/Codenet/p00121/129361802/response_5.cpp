#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
char bj[8];
int dp[9][362880], fact[9], vis[362880], pre[9][362880], prestep[9][362880];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dir[4] = {'u', 'd', 'l', 'r'};
struct node {
    int a[9], x, y, step;
    int hash() {
        int i, j, k = 0;
        for (i = 0; i < 9; i++) {
            int cnt = 0;
            for (j = i + 1; j < 9; j++)
                if (a[j] < a[i]) cnt++;
            k += cnt * fact[8 - i];
        }
        return k + 1;
    }
} start;
void bfs() {
    int i, j;
    memset(vis, 0, sizeof(vis));
    queue<node> Q;
    start.step = 0;
    vis[start.hash()] = 1;
    Q.push(start);
    while (!Q.empty()) {
        node now = Q.front();
        Q.pop();
        node next = now;
        next.step = now.step + 1;
        for (i = 0; i < 4; i++) {
            next.x = now.x + dx[i];
            next.y = now.y + dy[i];
            if (next.x >= 0 && next.x < 3 && next.y >= 0 && next.y < 3) {
                swap(next.a[next.x * 3 + next.y], next.a[now.x * 3 + now.y]);
                int h = next.hash();
                if (!vis[h]) {
                    vis[h] = 1;
                    Q.push(next);
                    pre[next.x * 3 + next.y][h] = now.x * 3 + now.y;
                    prestep[next.x * 3 + next.y][h] = dir[i];
                }
                swap(next.a[next.x * 3 + next.y], next.a[now.x * 3 + now.y]);
            }
        }
    }
}
int main() {
    fact[0] = 1;
    for (int i = 1; i <= 8; i++) fact[i] = fact[i - 1] * i;
    while (1) {
        for (int i = 0; i < 9; i++)
            if (scanf("%c", &bj[i]) == EOF) return 0;
        getchar();
        for (int i = 0; i < 9; i++) {
            if (bj[i] == '0') {
                bj[i] = '9';
                start.x = i / 3;
                start.y = i % 3;
            }
            start.a[i] = bj[i] - '0';
        }
        bfs();
        if (vis[322880]) printf("%d\n", dp[start.x * 3 + start.y][322880]);
        else printf("-1\n");
        while (getchar() != '\n')
            ;
    }
    return 0;
}