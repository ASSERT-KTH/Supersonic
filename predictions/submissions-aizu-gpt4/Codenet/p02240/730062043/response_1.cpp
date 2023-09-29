#include <iostream>
using namespace std;

int join[100000], num[100000];

int find(int x) {
    return (x == join[x]) ? x : (join[x] = find(join[x]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, s, t;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        join[i] = i;
        num[i] = 0;
    }

    while (m--) {
        cin >> s >> t;
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
    cin >> q;

    while (q--) {
        cin >> s >> t;
        if (find(s) == find(t))
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}