#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, a;
    while (true) {
        cin >> n >> m >> a;
        if (n == 0 && m == 0 && a == 0) {
            break;
        }
        vector<vector<int>> amida(n+2, vector<int>(m+2, 0));
        for (int i = 0; i < m; i++) {
            int h = 0, p = 0, q = 0;
            cin >> h >> p >> q;
            amida[p][h] = 1;
        }
        for (int j = m+1; j > 0; j--) {
            if (amida[a][j] == 1)
                a++;
            else if (amida[a - 1][j] == 1)
                a--;
        }
        cout << a << "\n";
    }
    return 0;
}