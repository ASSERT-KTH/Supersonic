#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    vector<int> b(m);
    for (int j = 0; j < m; ++j)
        cin >> b[j];

    for (int i = 0; i < n; ++i) {
        int c = 0;
        for (int j = 0; j < m; ++j)
            c += a[i][j] * b[j];
        cout << c << "\n";
    }

    return 0;
}