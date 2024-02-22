#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, b) for (int i = 0; i < b; i++)
#define m_t 60
#define max (3 * m_t * (m_t + 1) + 1)
#define zero (max / 2)
#define mp make_pair
int dx[6] = { 0, 1, -1, 1, -1, 0 };
int dy[6] = { 1, 1, 0, 0, -1, -1 };
int field[max];
int t, n;
int cnt;

// Optimized breadth-first search
int bfs(int sx, int sy) {
    int queue[max];
    int front = 0;
    int rear = 0;
    int ans = 0;

    // Push initial position onto the queue
    queue[rear++] = sx;
    queue[rear++] = sy;
    queue[rear++] = 0;

    while (front < rear) {
        ans++;

        int cx = queue[front++];
        int cy = queue[front++];
        int ct = queue[front++];

        if (ct < t) {
            for (int i = 0; i < 6; i++) {
                int nx = cx + dx[i];
                int ny = (cy + dy[i]) * (m_t * 2 + m_t * 2 + 1 - abs(cy + dy[i])) / 2;

                if (field[zero + nx + ny]) {
                    field[zero + nx + ny] = 0;

                    // Push new position onto the queue
                    queue[rear++] = nx;
                    queue[rear++] = cy + dy[i];
                    queue[rear++] = ct + 1;
                }
            }
        }
    }

    return ans;
}

int main() {
    while (cin >> t >> n, t) {
        fill(field, field + max, 1);
        int x, y;
        rep(i, n) {
            cin >> x >> y;
            y = y * (m_t * 2 + m_t * 2 + 1 - abs(y)) / 2;
            field[zero + x + y] = 0;
        }
        int sx, sy;
        cin >> sx >> sy;
        x = sx;
        y = sy * (m_t * 2 + m_t * 2 + 1 - abs(sy)) / 2;
        field[zero + x + y] = 0;

        int ans = bfs(sx, sy);
        cout << ans << endl;
    }
}