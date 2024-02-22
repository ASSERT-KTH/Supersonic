#include <iostream>
#include <cstring>

void func(int, int);
int jump(int, int);

int main() {
    int X, Y;
    while (1) {
        std::cin >> X >> Y;
        if (X == 0 && Y == 0)
            break;

        int data[Y][X], memo[Y][X];
        std::memset(data, 0, sizeof(data));
        std::memset(memo, 0, sizeof(memo));

        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                std::cin >> data[i][j];
            }
        }

        for (int i = 0; i < X; i++) {
            if (data[0][i] == 0)
                func(0, i);
        }

        int cnt = 0;
        for (int i = 0; i < X; i++) {
            cnt += memo[0][i];
        }
        std::cout << cnt << std::endl;
    }
}

void func(int y, int x) {
    if (data[y + 1][x] == 2) {
        int r = jump(y + 1, x);
        if (r == -2) {
            memo[y][x] += 1;
            return;
        } else if (r != -1) {
            if (memo[r][x] == 0)
                func(r, x);
            memo[y][x] += memo[r][x];
        }
    }

    int memo_y_plus_1_x_minus_1 = memo[y + 1][x - 1];
    int memo_y_plus_1_x_plus_1 = memo[y + 1][x + 1];
    int memo_y_plus_1_x = memo[y + 1][x];

    if (0 <= x - 1 && data[y + 1][x - 1] == 0) {
        if (memo_y_plus_1_x_minus_1 == 0)
            func(y + 1, x - 1);
        memo[y][x] += memo_y_plus_1_x_minus_1;
    }
    if (x + 1 < X && data[y + 1][x + 1] == 0) {
        if (memo_y_plus_1_x_plus_1 == 0)
            func(y + 1, x + 1);
        memo[y][x] += memo_y_plus_1_x_plus_1;
    }
    if (data[y + 1][x] == 0) {
        if (memo_y_plus_1_x == 0)
            func(y + 1, x);
        memo[y][x] += memo_y_plus_1_x;
    }
    if (memo[y][x] == 0)
        data[y][x] = 1;
}

int jump(int y, int x) {
    while (1) {
        y += 2;
        if (data[y][x] == 1)
            break;
        if (y >= Y - 1)
            return -2;
        if (data[y][x] == 0)
            return y;
    }
    return -1;
}