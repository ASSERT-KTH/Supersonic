#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], N[MAX_M], path[MAX_M];
bool visit[MAX_M];

bool isPositionValid(int p) { return 0 <= p && p < M; }

void MakePath() {
    for (int i = 0; i < M; i++) path[i] = MAX_T + 1;
    queue<int> q;
    q.push(goal);
    path[goal] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (visit[cur]) continue;
        visit[cur] = true;
        for (int r = 0; r < 6; r++) {
            int moveto = cur + dice[r];
            if (isPositionValid(moveto)) {
                int position = moveto + N[moveto];
                if (!visit[position] && path[position] > path[cur] + 1) {
                    path[position] = path[cur] + 1;
                    q.push(position);
                }
            }
            moveto = cur - dice[r];
            if (isPositionValid(moveto)) {
                int position = moveto + N[moveto];
                if (!visit[position] && path[position] > path[cur] + 1) {
                    path[position] = path[cur] + 1;
                    q.push(position);
                }
            }
        }
    }
}

int main() {
    cin >> M;
    for (int r = 0; r < 6; r++) cin >> dice[r];
    cin >> start >> goal;
    start--, goal--;
    for (int m = 0; m < M; m++) cin >> N[m];
    memset(visit, false, sizeof(visit));
    MakePath();
    int position = start;
    for (int t = 0; t < MAX_T; t++) {
        if (position == goal) break;
        int r; cin >> r;
        int d = dice[r - 1];
        int output;
        if (isPositionValid(position + d) && path[position + d + N[position + d]] < path[position + N[position]]) {
            position = position + d + N[position + d];
            output = 1;
        } else if (isPositionValid(position - d) && path[position - d + N[position - d]] < path[position + N[position]]) {
            position = position - d + N[position - d];
            output = -1;
        } else {
            output = 0;
        }
        cout << output << endl;
    }
    return 0;
}