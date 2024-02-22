#include <cstdio>
#include <vector>
using namespace std;

vector<int> join, num;

int find(int x) {
    while(x != join[x]) {
        join[x] = join[join[x]]; // path compression
        x = join[x];
    }
    return x;
}

int main() {
    int n, m, s, t;
    scanf("%d %d", &n, &m);
    
    join.resize(n);
    num.resize(n, 0);
    
    for (int i = 0; i < n; i++) {
        join[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
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
    
    int q;
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &s, &t);
        if (find(s) == find(t))
            printf("yes\n");
        else
            printf("no\n");
    }
    
    return 0;
}