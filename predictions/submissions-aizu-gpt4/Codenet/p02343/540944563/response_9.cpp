#include <cstdio>

const int N_MAX = 200005;

int parent[N_MAX];
int rank_[N_MAX];

int find(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rank_[x] < rank_[y]) {
        parent[x] = y;
    } else {
        parent[y] = x;
        if(rank_[x] == rank_[y]) rank_[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    for(int i = 0; i < N; ++i) {
        parent[i] = i;
        rank_[i] = 0;
    }

    for(int i = 0; i < Q; ++i) {
        int cmd, x, y;
        scanf("%d %d %d", &cmd, &x, &y);
        if(cmd == 0) {
            unite(x, y);
        } else {
            printf("%d\n", same(x, y));
        }
    }

    return 0;
}