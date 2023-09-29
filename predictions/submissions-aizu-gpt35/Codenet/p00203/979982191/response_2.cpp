#include <iostream>
#include <cstring>
#define N 15
using namespace std;

int X, Y, data[N][N], memo[N][N];

void func(int y, int x) {
    if (y == Y - 1) {
        memo[Y - 1][x] = 1;
        return;
    }
    if (data[y + 1][x] == 0) {
        if (memo[y + 1][x] == 0)
            func(y + 1, x);
        memo[y][x] += memo[y + 1][x];
    }
    if (data[y + 1][x] == 2) {
        int r = y + 2;
        while (data[r][x] == 2) r += 2;
        if (data[r][x] == 0) {
            if (memo[r][x] == 0) func(r, x);
            memo[y][x] += memo[r][x];
        }
    }
    if (x + 1 < X && data[y + 1][x + 1] != 1) {
        if (memo[y + 1][x + 1] == 0)
            func(y + 1, x + 1);
        memo[y][x] += memo[y + 1][x + 1];
    }
    if (x - 1 >= 0 && data[y + 1][x - 1] != 1) {
        if (memo[y + 1][x - 1] == 0)
            func(y + 1, x - 1);
        memo[y][x] += memo[y + 1][x - 1];
    }
    if (memo[y][x] == 0)
        data[y][x] = 1;
}

int main() {
    while (1) {
        cin >> X >> Y;
        if (X == 0 && Y == 0)
            break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                data[i][j] = 1;
            }
        }
        for (int i = 0; i < Y; i++)
            for (int j = 0; j < X; j++)
                cin >> data[i][j], memo[i][j] = 0;
        for (int i = 0; i < X; i++)
            if (data[0][i] == 0)
                func(0, i);
        int cnt = 0;
        for (int i = 0; i < X; i++)
            cnt += memo[0][i];
        cout << cnt << endl;
    }
    return 0;
}