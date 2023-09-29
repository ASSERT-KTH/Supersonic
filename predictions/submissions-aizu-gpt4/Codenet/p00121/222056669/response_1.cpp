#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int maxn = 1000000;

char num[10];
char vis[maxn + 5];
int d[10];
int head, tail, q[maxn * 20 + 5], step[maxn * 20 + 5], zero[maxn * 20 + 5];

void bfs() {
    int s = 0;
    for (int i = 0; i < 8; i++) {
        if (num[i] == '0') {
            zero[head] = i;
        }
        s = s * 10 + num[i] - '0';
    }
    q[head] = s;
    while (head <= tail) {
        int u = q[head];
        int z = zero[head];
        int v = u;
        for (int i = 7; i >= 0; i--) {
            d[i] = v % 10;
            v /= 10;
        }
        static int dx[] = {-1, 1, -4, 4};
        for (int i = 0; i < 4; i++) {
            int nz = z + dx[i];
            if (nz < 0 || nz >= 8 || (z == 3 && nz == 4) || (z == 4 && nz == 3)) {
                continue;
            }
            swap(d[z], d[nz]);
            v = 0;
            for (int j = 0; j < 8; j++) {
                v = v * 10 + d[j];
            }
            if (!vis[v]) {
                vis[v] = 1;
                q[++tail] = v;
                zero[tail] = nz;
                step[tail] = step[head] + 1;
                if (v == 12345678) {
                    return;
                }
            }
            swap(d[z], d[nz]);
        }
        head++;
    }
}

int main() {
    while (scanf("%c", &num[0]) != EOF) {
        for (int i = 1; i < 8; i++) {
            getchar();
            scanf("%c", &num[i]);
        }
        memset(vis, 0, sizeof(vis));
        head = tail = 1;
        vis[atoi(num)] = 1;
        step[1] = 0;
        bfs();
        if (vis[12345678]) {
            printf("%d\n", step[tail]);
        } else {
            printf("-1\n");
        }
        getchar();
    }
    return 0;
}