#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> V;

void solve(int M[9][9], int y, int x) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    M[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 3; j++) {
            if (y + dy[i] * j >= 0 && y + dy[i] * j < 8 && x + dx[i] * j >= 0 && x + dx[i] * j < 8) {
                int ny = y + dy[i] * j, nx = x + dx[i] * j;
                if (M[ny][nx] == 1)
                    solve(M, ny, nx);
            }
        }
    }
}

int main() {
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int M[9][9];
        string s;
        for (int j = 0; j < 8; j++) {
            cin >> s;
            for (int k = 0; k < 8; k++) {
                M[j][k] = s[k] - '0';
            }
        }
        cin >> x >> y;
        solve(M, y - 1, x - 1);
        cout << "Data " << i + 1 << ":" << endl;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                cout << M[j][k];
            }
            cout << endl;
        }
    }
}