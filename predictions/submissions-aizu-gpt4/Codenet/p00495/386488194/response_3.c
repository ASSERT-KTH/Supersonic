#include <cstdio>
#include <algorithm>

int c[5004], d[5004], m, t, u, i;
char f[] = "%d";

int main() {
    std::fill(c, c + 5004, 0);
    std::fill(d, d + 5004, 0);
    m = t = u = i = 0;
    
    scanf(f, c);
    for (; i < *c; scanf(f, ++i + c));
    
    int x;
    while(~scanf(f, &x)) {
        u = i = t = 0;
        m = 0;
        for (; i++ < *c; t = d[i], d[i] = std::max(m, u))
            u = (x != c[i]) ? u : t + 1, m = std::max(m, u);
    }
    printf(f, m);
    return 0;
}