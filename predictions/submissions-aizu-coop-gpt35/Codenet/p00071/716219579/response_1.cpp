#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void markAdjacentCells(int y, int x, int* result) {
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};
    stack<pair<int, int>> stk;
    stk.push({y, x});
    result[y * 8 + x] = 0;

    while (!stk.empty()) {
        int currY = stk.top().first;
        int currX = stk.top().second;
        stk.pop();

        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= 3; j++) {
                int ny = currY + dy[i] * j;
                int nx = currX + dx[i] * j;

                if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8) {
                    int index = ny * 8 + nx;
                    if (result[index] == 1) {
                        result[index] = 0;
                        stk.push({ny, nx});
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int result[64];
        for (int j = 0; j < 8; j++) {
            string s;
            cin >> s;
            for (int k = 0; k < 8; k++) {
                result[j * 8 + k] = s[k] - '0';
            }
        }

        int x, y;
        cin >> x >> y;

        markAdjacentCells(y - 1, x - 1, result);

        cout << "Data " << i + 1 << ":" << endl;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                cout << result[j * 8 + k];
            }
            cout << endl;
        }
    }

    return 0;
}