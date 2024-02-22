#include <iostream>
#include <vector>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

vector<vector<int>> solve(vector<vector<int>>& M, int y, int x) {
    M[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 3; j++) {
            int ny = y + dy[i] * j, nx = x + dx[i] * j;
            if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8) {
                if (M[ny][nx] == 1)
                    solve(M, ny, nx);
            }
        }
    }
    return M;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        vector<vector<int>> M(8, vector<int>(8));
        for (int j = 0; j < 8; j++) {
            string line;
            getline(cin, line);
            for (int k = 0; k < 8; k++) {
                M[j][k] = line[k] - '0';
            }
        }
        int x, y;
        cin >> x >> y;
        M = solve(M, y - 1, x - 1);
        cout << "Data " << i + 1 << ":" << endl;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                cout << M[j][k];
            }
            cout << endl;
        }
    }
    return 0;
}