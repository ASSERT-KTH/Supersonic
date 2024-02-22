#include <iostream>

const int MAX_H = 51;
const int MAX_W = 51;

char mp[2][MAX_H][MAX_W];
bool visited[MAX_H][MAX_W][MAX_H][MAX_W];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool bfs(int lx, int ly, int rx, int ry, int h, int w) {
    bool visited[MAX_H][MAX_W][MAX_H][MAX_W] = { false }; // Reset visited state

    bool queue1[MAX_H*MAX_W*MAX_H*MAX_W] = { false };
    bool queue2[MAX_H*MAX_W*MAX_H*MAX_W] = { false };
    int front1 = 0, back1 = 0;
    int front2 = 0, back2 = 0;

    queue1[back1++] = lx;
    queue1[back1++] = ly;
    queue2[back2++] = rx;
    queue2[back2++] = ry;

    while (front1 < back1 && front2 < back2) {
        int lx = queue1[front1++];
        int ly = queue1[front1++];
        int rx = queue2[front2++];
        int ry = queue2[front2++];

        int cnt = (mp[0][ly][lx] == '%') + (mp[1][ry][rx] == '%');
        if (cnt == 2) {
            return true;
        }

        if (visited[lx][ly][rx][ry] || cnt == 1) {
            continue;
        }

        visited[lx][ly][rx][ry] = true;

        for (int i = 0; i < 4; i++) {
            int nlx = lx + dx[i];
            int nly = ly + dy[i];
            int nrx = rx - dx[i];
            int nry = ry + dy[i];

            if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nly][nlx] == '#') {
                nlx = lx;
                nly = ly;
            }

            if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nry][nrx] == '#') {
                nrx = rx;
                nry = ry;
            }

            if (!visited[nlx][nly][nrx][nry]) {
                queue1[back1++] = nlx;
                queue1[back1++] = nly;
                queue2[back2++] = nrx;
                queue2[back2++] = nry;
            }
        }
    }

    return false;
}

int main() {
    int w, h;
    while (true) {
        std::cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }

        for (int i = 0; i < h; i++) {
            std::cin >> mp[0][i] >> mp[1][i];
        }

        int lx, ly, rx, ry;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (mp[0][i][j] == 'L') {
                    lx = j;
                    ly = i;
                }
                if (mp[1][i][j] == 'R') {
                    rx = j;
                    ry = i;
                }
            }
        }

        if (bfs(lx, ly, rx, ry, h, w)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}