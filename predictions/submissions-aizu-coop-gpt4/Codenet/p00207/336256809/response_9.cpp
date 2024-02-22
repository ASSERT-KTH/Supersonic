#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void meiro(int W, int H, int c, vector<vector<int>>& C){
    stack<pair<int, int>> stk;
    stk.push({W, H});

    while(!stk.empty()){
        int x = stk.top().first;
        int y = stk.top().second;
        stk.pop();

        if(x < 0 || y < 0 || x >= W || y >= H || C[x][y] != c) 
            continue;

        C[x][y] = -1;
        stk.push({x-1, y});
        stk.push({x, y+1});
        stk.push({x+1, y});
        stk.push({x, y-1});
    }
}

int main(){
    while(true){
        int w, h;
        scanf("%d %d", &w, &h);
        if(w == 0 && h == 0) 
            break;

        vector<vector<int>> C(max(w,h), vector<int>(max(w,h), 10));

        int xs, ys, xg, yg;
        scanf("%d %d %d %d", &xs, &ys, &xg, &yg);

        int n;
        scanf("%d", &n);

        int c, d, x, y;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &c, &d, &x, &y);
            if (d == 0) {
                for (int j = x; j < x + 4; j++) {
                    for (int k = y; k < y + 2; k++) {
                        C[j][k] = c;
                    }
                }
            } else {
                for (int j = x; j < x + 2; j++) {
                    for (int k = y; k < y + 4; k++) {
                        C[j][k] = c;
                    }
                }
            }
        }

        meiro(xs, ys, C[xs][ys], C);

        if (C[xg][yg] == -1) {
            printf("OK\n");
        } else {
            printf("NG\n");
        }
    }
    return 0;
}