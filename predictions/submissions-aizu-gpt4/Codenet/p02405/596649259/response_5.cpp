#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W;
    while (cin >> H >> W && H != 0 && W != 0) {
        vector<string> grid(H, string(W, '.'));
        for (int i = 0; i < H; ++i) {
            for (int j = i & 1; j < W; j += 2) {
                grid[i][j] = '#';
            }
        }
        for (const auto& row : grid) {
            cout << row << '\n';
        }
        cout << '\n';
    }
    return 0;
}