#include <iostream>
#include <vector>
#define N 15
using namespace std;
int X, Y;
vector<vector<int>> memo(N, vector<int>(N, -1));
vector<vector<int>> data(N, vector<int>(N, 0));
int func(int y, int x) {
    if(y == Y - 1) return 1;
    if(memo[y][x] != -1) return memo[y][x];
    int ways = 0;
    if (0 <= x - 1 && data[y + 1][x - 1] == 0) ways += func(y + 1, x - 1);
    if (x + 1 < X && data[y + 1][x + 1] == 0) ways += func(y + 1, x + 1);
    if (data[y + 1][x] == 0) ways += func(y + 1, x);
    if (data[y + 1][x] == 2) {
        int r = y + 2;
        while(r < Y && data[r][x] == 2) r += 2;
        if(r < Y && data[r][x] == 0) ways += func(r, x);
        else if(r >= Y) ways += 1;
    }
    return memo[y][x] = ways;
}  
int main() {
    while (1) {
        cin >> X >> Y;
        if (X == 0 && Y == 0) break;
        fill(data.begin(), data.end(), vector<int>(N, 0));
        fill(memo.begin(), memo.end(), vector<int>(N, -1));
        for (int i = 0; i < Y; i++)
            for (int j = 0; j < X; j++)
                cin >> data[i][j];
        int cnt = 0;
        for (int i = 0; i < X; i++)
            if (data[0][i] == 0) cnt += func(0, i);
        cout << cnt << endl;
    }
    return 0;
}