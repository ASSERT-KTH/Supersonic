#include <iostream>
using namespace std;

int C[102][102];

void meiro(int W, int H, int c) {
    C[W][H] = -1;
    
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    for (int i = 0; i < 4; i++) {
        int newW = W + dirs[i][0];
        int newH = H + dirs[i][1];
        
        if (C[newW][newH] == c) {
            meiro(newW, newH, c);
        }
    }
}

int main() {
    while (1) {
        int w, h;
        cin >> w >> h;
        
        if (w == 0 && h == 0) {
            break;
        }
        
        for (int i = 0; i <= w + 1; i++) {
            for (int j = 0; j <= h + 1; j++) {
                if (i == 0 || i == w + 1 || j == 0 || j == h + 1) {
                    C[i][j] = -1; // Set the boundary cells to -1
                } else {
                    C[i][j] = 10;
                }
            }
        }
        
        int xs, ys, xg, yg;
        cin >> xs >> ys >> xg >> yg;
        
        int n;
        cin >> n;
        
        int c, d, x, y;
        
        for (int i = 0; i < n; i++) {
            cin >> c >> d >> x >> y;
            
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
        
        meiro(xs, ys, C[xs][ys]);
        
        if (C[xg][yg] == -1) {
            cout << "OK" << endl;
        } else {
            cout << "NG" << endl;
        }
    }
    
    return 0;
}