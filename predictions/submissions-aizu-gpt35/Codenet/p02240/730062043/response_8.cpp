#include <iostream>
using namespace std;

int find(int join[], int x, int num[]) {
    if (x == join[x])
        return x;
    return join[x] = find(join, join[x], num);
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, join[100000], num[100000] = {0}, s, t;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        join[i] = i;

    for (int i = 0; i < m; i++) {
        cin >> s >> t;
        s = find(join, s, num);
        t = find(join, t, num);
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
    cin >> q;
    while (q--) {
        cin >> s >> t;
        if (find(join, s, num) == find(join, t, num))
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}