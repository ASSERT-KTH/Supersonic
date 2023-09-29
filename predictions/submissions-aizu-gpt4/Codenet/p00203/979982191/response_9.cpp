#include <iostream>
#include <vector>
#define N 15
using namespace std;

void func(int, int);
int jump(int, int);

int X, Y;
vector<vector<int>> data(N, vector<int>(N, 0)), memo(N, vector<int>(N, 0));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> X >> Y, X || Y) {
        for(auto &row : data) fill(row.begin(), row.begin() + X, 0);
        for(auto &row : memo) fill(row.begin(), row.begin() + X, 0);

        for (int i = 0; i < Y; i++)
            for (int j = 0; j < X; j++)
                cin >> data[i][j];

        for (int i = 0; i < X; i++)
            if (data[0][i] == 0)
                func(0, i);

        cout << accumulate(memo[0].begin(), memo[0].begin()+X, 0) << endl;
    }
    return 0;
}

void func(int y, int x) {
    if (y == Y - 1) {
        memo[y][x] = 1;
        return;
    }
    for(int dx = -1; dx <= 1; dx++) {
        if(x + dx < 0 || x + dx >= X || data[y + 1][x + dx] == 1) continue;
        if(dx == 0 && data[y+1][x] == 2) {
            int r = jump(y + 1, x);
            if (r == -2)
                memo[y][x] += 1;
            else if (r != -1) {
                if (memo[r][x] == 0)
                    func(r, x);
                memo[y][x] += memo[r][x];
            }
        }
        else if(data[y + 1][x + dx] == 0) {
            if (memo[y + 1][x + dx] == 0)
                func(y + 1, x + dx);
            memo[y][x] += memo[y + 1][x + dx];
        }
    }
}

int jump(int y, int x) {
    while (y + 2 < Y && data[y + 2][x] != 1) {
        y += 2;
        if (data[y][x] == 0) return y;
    }
    return y + 2 >= Y ? -2 : -1;
}