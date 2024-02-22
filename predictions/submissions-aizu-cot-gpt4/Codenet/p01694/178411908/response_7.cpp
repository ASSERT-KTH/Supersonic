#include <cstdio>
enum Direction { lu, ru, ld, rd };

Direction toDirection(const char* str) {
    switch (str[0]) {
        case 'l': return (str[1] == 'u') ? lu : ld;
        case 'r': return (str[1] == 'u') ? ru : rd;
        default: return lu; // just to avoid compiler warning
    }
}

int main() {
    int n;
    while (scanf("%d", &n), n) {
        int ans = 0;
        Direction now = lu, next;
        char str[3];
        for (int i = 0; i < n; ++i) {
            scanf("%s", str);
            next = toDirection(str);
            if ((now == lu && next == ru) || (now == ru && next == lu) || 
                (now == ld && next == rd) || (now == rd && next == ld))
                ans++;
            now = next;
        }
        printf("%d\n", ans);
    }
    return 0;
}