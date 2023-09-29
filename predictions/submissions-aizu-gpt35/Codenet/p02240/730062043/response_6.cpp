#include <iostream>
using namespace std;

const int MAXN = 100000;

int find(int join[], int x, int rank[]) {
    if (x == join[x])
        return x;
    return join[x] = find(join, join[x], rank);
}

void merge(int join[], int rank[], int x, int y) {
    x = find(join, x, rank);
    y = find(join, y, rank);
    if (x != y) {
        if (rank[x] < rank[y])
            swap(x, y);
        join[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    int join[MAXN + 5], rank[MAXN + 5];
    int s, t;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        join[i] = i;
        rank[i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        cin >> s >> t;
        merge(join, rank, s, t);
    }

    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> s >> t;
        if (find(join, s, rank) == find(join, t, rank))
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}