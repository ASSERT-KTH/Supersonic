#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a;
    while (cin >> n >> m >> a && n && m && a) {
        vector<vector<int>> amida(n+1, vector<int>(m+1, 0));
        for (int i = 0; i < m; ++i) {
            int h, p;
            cin >> h >> p;
            amida[p][h] = 1;
        }
        for (int j = m; j > 0; --j) {
            if (a < n && amida[a+1][j]) ++a;
            else if (a > 1 && amida[a][j]) --a;
        }
        cout << a << '\n';
    }

    return 0;
}