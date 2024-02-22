#include <iostream>
#define N 15
using namespace std;

void func(int, int, int, int);
int jump(int, int, int, int);

int main() {
    int X, Y;
    while (1) {
        cin >> X >> Y;
        if (X == 0 && Y == 0)
            break;
        
        int data[N][N] = {0};
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                cin >> data[i][j];
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < X; i++) {
            if (data[0][i] == 0) {
                func(0, i, Y, X);
                cnt += data[0][i];
            }
        }
        
        cout << cnt << endl;
    }

    return 0;
}

void func(int y, int x, int Y, int X) {
    static bool memo[N][N] = {false};
    
    if (y == Y - 1) {
        memo[y][x] = true;
        return;
    }
    
    if (0 <= x - 1 && data[y + 1][x - 1] == 0) {
        if (!memo[y + 1][x - 1]) {
            func(y + 1, x - 1, Y, X);
        }
        memo[y][x] += memo[y + 1][x - 1];
    }
    
    if (x + 1 < X && data[y + 1][x + 1] == 0) {
        if (!memo[y + 1][x + 1]) {
            func(y + 1, x + 1, Y, X);
        }
        memo[y][x] += memo[y + 1][x + 1];
    }
    
    if (data[y + 1][x] == 0) {
        if (!memo[y + 1][x]) {
            func(y + 1, x, Y, X);
        }
        memo[y][x] += memo[y + 1][x];
    }
    
    if (data[y + 1][x] == 2) {
        int r = jump(y + 1, x, Y, X);
        if (r == -2) {
            memo[y][x] += 1;
        } else if (r != -1) {
            if (!memo[r][x]) {
                func(r, x, Y, X);
            }
            memo[y][x] += memo[r][x];
        }
    }
    
    if (memo[y][x] == 0) {
        data[y][x] = 1;
    }
}

int jump(int y, int x, int Y, int X) {
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