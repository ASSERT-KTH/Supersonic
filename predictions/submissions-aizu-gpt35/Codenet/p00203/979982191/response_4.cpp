#include <iostream>
#include <cstring>
#define N 15
using namespace std;
int X, Y, data[N][N], memo[N][N];
int func(int, int);
int jump(int, int);
int main() {
    ios_base::sync_with_stdio(false); //to optimize input/output operations
    cin.tie(NULL); //to optimize input/output operations
    while (1) {
        cin >> X >> Y;
        if (X == 0 && Y == 0)
            break;
        memset(data, 0, sizeof(data)); //to initialize 'data' array to 0
        memset(memo, 0, sizeof(memo)); //to initialize 'memo' array to 0
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                cin >> data[i][j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < X; i++) {
            if (data[0][i] == 0) {
                cnt += func(0, i);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
int func(int y, int x) {
    if (y == Y - 1) {
        memo[Y - 1][x] = 1;
        return 1;
    }
    if (memo[y][x] != 0) {
        return memo[y][x];
    }
    int res = 0;
    if (0 <= x - 1 && data[y + 1][x - 1] == 0) {
        res += func(y + 1, x - 1);
    }
    if (x + 1 < X && data[y + 1][x + 1] == 0) {
        res += func(y + 1, x + 1);
    }
    if (data[y + 1][x] == 0) {
        res += func(y + 1, x);
    }
    if (data[y + 1][x] == 2) {
        int r = jump(y + 1, x);
        if (r == -2) {
            res += 1;
        }
        else if (r != -1) {
            res += func(r, x);
        }
    }
    memo[y][x] = res;
    return res;
}
int jump(int y, int x) {
    while (1) {
        y += 2;
        if (data[y][x] == 1) {
            break;
        }
        if (y >= Y - 1) {
            return -2;
        }
        if (data[y][x] == 0) {
            return y;
        }
    }
    return -1;
}