#include <iostream>
using namespace std;

int** createMaze(int W, int H) {
    int** C = new int*[W];
    for (int i = 0; i < W; i++) {
        C[i] = new int[H];
        for (int j = 0; j < H; j++) {
            C[i][j] = 10;
        }
    }
    return C;
}

void deleteMaze(int** C, int W) {
    for (int i = 0; i < W; i++) {
        delete[] C[i];
    }
    delete[] C;
}

void meiro(int W, int H, int** C, int c) {
    if (C[W][H] != c) {
        return;
    }
    C[W][H] = -1;

    // Check and visit neighboring cells
    if (W > 0) {
        if (C[W - 1][H] == c) {
            meiro(W - 1, H, C, c);
        }
    }
    if (H < 101) {
        if (C[W][H + 1] == c) {
            meiro(W, H + 1, C, c);
        }
    }
    if (W < 101) {
        if (C[W + 1][H] == c) {
            meiro(W + 1, H, C, c);
        }
    }
    if (H > 0) {
        if (C[W][H - 1] == c) {
            meiro(W, H - 1, C, c);
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
        int** C = createMaze(w, h);

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

        meiro(xs, ys, C, C[xs][ys]);

        if (C[xg][yg] == -1) {
            cout << "OK" << endl;
        } else {
            cout << "NG" << endl;
        }

        deleteMaze(C, w);
    }
    return 0;
}