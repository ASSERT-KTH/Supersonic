#include <cstdio>
using namespace std;

int main() {
    int n, m, o[100], b[100];
    int ans;
    for (;;) {
        scanf("%d %d", &n, &m);
        if (!n && !m)
            break;
        ans = 0;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < 8; j++) {
                char ch;
                scanf(" %c", &ch);
                if (ch == '*') {
                    mask |= (1 << j);
                }
            }
            b[i] = mask;
            scanf("%d", &o[i]);
        }
        for (int i = 0; i < m; i++) {
            int mask = 0;
            for (int j = 0; j < 8; j++) {
                char ch;
                scanf(" %c", &ch);
                mask |= (1 << j);
            }
            for (int j = 0; j < n; j++) {
                if (b[j] & mask) {
                    ans += o[j];
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}