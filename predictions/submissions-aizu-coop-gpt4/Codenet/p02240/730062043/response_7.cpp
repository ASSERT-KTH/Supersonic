#include <cstdio>
#define MAXN 100000

int join[MAXN], num[MAXN];

int find(int x) {
    while(x != join[x]) {
        join[x] = join[join[x]]; // path compression
        x = join[x];
    }
    return x;
}

int main() {
    int n, m, s, t, q;
    scanf("%d %d", &n, &m);
  
    for (int i = 0; i < n; i++) {
        join[i] = i;
        num[i] = 0;
    }
  
    while(m--) {
        scanf("%d %d", &s, &t);
        s = find(s);
        t = find(t);
        if (s != t) {
            if (num[s] < num[t])
                join[s] = join[t];
            else {
                join[t] = join[s];
                if (num[s] == num[t])
                    num[s]++;
            }
        }
    }
  
    scanf("%d", &q);
    while(q--) {
        scanf("%d %d", &s, &t);
        if (find(s) == find(t))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
