#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int T, n;
bool vis[MAXN];
int get_next(int x) {
    int ret = 1;
    while (x) {
        if (x % 10) ret *= x % 10;
        x /= 10;
    }
    return ret;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        int cnt = 0;
        while (!vis[n]) {
            cnt++;
            if (n == 1) break;
            vis[n] = 1;
            n = get_next(n);
        }
        if (n == 1) printf("%d\n", cnt);
        else puts("-1");
    }
    return 0;
}