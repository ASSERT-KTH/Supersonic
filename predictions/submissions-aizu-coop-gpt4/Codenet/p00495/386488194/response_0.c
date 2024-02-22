#include <stdio.h>
#include <unordered_map>

int c[5004], d[5004], m, t, u, i, f = "%d\n";
std::unordered_map<int, int> last;

int main() {
    scanf("%d%*d", &c[0]);
    for(i = 1; i <= c[0]; scanf("%d", &c[i++]));
    for (; ~scanf("%d", &x);) {
        for (u = i = t = m = 0; i <= c[0]; i++) {
            t = d[i];
            d[i] = m < u ? m = u : u;
            u = last.count(x) ? d[last[x]] + 1 : u;
            last[c[i]] = i;
        }
    }
    m = !printf(f, m);
    return 0;
}