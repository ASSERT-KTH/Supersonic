#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

struct Point {
    int x, y, dir, dist;
};

class Compare {
public:
    bool operator()(const Point &l, const Point &r) { return l.dist > r.dist; }
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dists[60][60][4];
vector<vector<int>> field;

int bfs(int startX, int startY, int goalX, int goalY) {
    vector<vector<int>> dist(field.size(), vector<int>(field[0].size(), INF));
    queue<Point> q;
    q.push({startX, startY, -1, 0});

    while (!q.empty()) {
        Point p = q.front(); q.pop();

        if (p.x == goalX && p.y == goalY) {
            return p.dist;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = p.x + dx[i], ny = p.y + dy[i];

            if (field[ny][nx] == 1 || dist[ny][nx] <= p.dist + 1) continue;

            dist[ny][nx] = p.dist + 1;
            q.push({nx, ny, i, p.dist + 1});
        }
    }

    return INF;
}

int main() {
    while (true) {
        int H, W; cin >> H >> W;
        if (H == 0 && W == 0) break;

        field = vector<vector<int>>(H + 2, vector<int>(W + 2, 1));
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < 60; ++j) {
                for (int k = 0; k < 4; ++k) {
                    dists[i][j][k] = INF;
                }
            }
        }

        int kx = INF, ky = INF, ox[2], oy[2], num = 0;
        for (int i = 1; i <= H; ++i) {
            string st; cin >> st;
            for (int j = 1; j <= W; ++j) {
                if (st[j - 1] == 'X') {
                    kx = min(kx, j);
                    ky = min(ky, i);
                    field[i][j] = 0;
                } else if (st[j - 1] == 'o') {
                    field[i][j] = 0;
                } else if (st[j - 1] == '.') {
                    field[i][j] = 0;
                    ox[num] = j;
                    oy[num] = i;
                    num++;
                }
            }
        }

        if (kx == 1 && ky == 1) {
            cout << 0 << endl;
            continue;
        }

        priority_queue<Point, vector<Point>, Compare> pq;
        for (int way = 0; way < 4; ++way) {
            int tmp = 0, gx = kx + dx[way], gy = ky + dy[way];
            for (int i = 0; i < 2; ++i) {
                int fx = ox[i], fy = oy[i];
                if (field[gy][gx] == 1) {
                    tmp = INF;
                    break;
                }
                tmp += bfs(fx, fy, gx, gy);
            }

            if (tmp < INF) {
                dists[kx][ky][way] = tmp;
                pq.push({kx, ky, way, tmp});
            }
        }

        int ans = -1;
        while (!pq.empty()) {
            Point p = pq.top(); pq.pop();

            if (p.x == 1 && p.y == 1) {
                ans = p.dist;
                break;
            }

            for (int tway = 0; tway < 4; ++tway) {
                if (p.dir == tway) continue;
                int tmp = 0, gx = p.x + dx[tway], gy = p.y + dy[tway];

                for (int i = 0; i < 2; ++i) {
                    int fx = p.x + dx[p.dir], fy = p.y + dy[p.dir];
                    if (i == 1) {
                        fx += dx[(p.dir + 1) % 4];
                        fy += dy[(p.dir + 1) % 4];
                    }
                    if (field[gy][gx] == 1) {
                        tmp = INF;
                        break;
                    }
                    tmp += bfs(fx, fy, gx, gy);
                }

                if (tmp < INF && dists[p.x][p.y][tway] > p.dist + tmp) {
                    dists[p.x][p.y][tway] = p.dist + tmp;
                    pq.push({p.x, p.y, tway, p.dist + tmp});
                }
            }

            int nx = p.x + dx[p.dir], ny = p.y + dy[p.dir], ndir = (p.dir + 2) % 4;
            if (dists[nx][ny][ndir] > p.dist + 1) {
                dists[nx][ny][ndir] = p.dist + 1;
                pq.push({nx, ny, ndir, p.dist + 1});
            }
        }

        cout << ans << endl;
    }

    return 0;
}