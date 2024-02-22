#include <cstdio>
#include <vector>
using namespace std;

int find(vector<int>& join, int x) {
    while (x != join[x]) {
        join[x] = join[join[x]]; // path compression
        x = join[x];
    }
    return x;
}

int main(int argc, char *argv[]) {
    int n, m, s, t, q;
    scanf("%d%d", &n, &m);
    vector<int> join(n), num(n);
    for (int i = 0; i < n; ++i) {
        join[i] = i;
        num[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &s, &t);
        s = find(join, s);
        t = find(join, t);
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
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &s, &t);
        if (find(join, s) == find(join, t))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}