#include <iostream>
#include <stack>
using namespace std;

int Board[102][102];
bool isOK;
int xs, ys, xg, yg;

void DFS(int c, int x, int y) {
    stack<pair<int, int>> s;
    s.push({x, y});
    
    while(!s.empty()) {
        int curr_x = s.top().first;
        int curr_y = s.top().second;
        s.pop();
        
        if (curr_x < 0 || curr_x >= 102 || curr_y < 0 || curr_y >= 102 || Board[curr_x][curr_y] != c) 
            continue;
        
        if (curr_x == xg && curr_y == yg) {
            isOK = true;
            return;
        }
        
        Board[curr_x][curr_y] = 0;
        s.push({curr_x + 1, curr_y});
        s.push({curr_x, curr_y + 1});
        s.push({curr_x - 1, curr_y});
        s.push({curr_x, curr_y - 1});
    }
}

int main() {
    int w, h;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        isOK = false;
        cin >> xs >> ys >> xg >> yg;
        int n, c, d, x, y;
        cin >> n;
        for (int t = 0; t < n; t++) {
            cin >> c >> d >> x >> y;
            int wb = 2 + (!d * 2);
            int hb = 2 + (d * 2);
            for (int i = 0; i < hb; i++) {
                for (int j = 0; j < wb; j++)
                    Board[x + j][y + i] = c;
            }
        }
        DFS(Board[xs][ys], xs, ys);
        if (isOK)
            cout << "OK" << endl;
        else
            cout << "NG" << endl;
    }
    return 0;
}