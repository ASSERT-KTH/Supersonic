#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], N[MAX_M], path[MAX_M];

bool isPositionValid(int p) { return 0 <= p && p < M; }

void MakePath() {
    queue<int> q;
    fill(path, path + M, MAX_T + 1);
    path[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for (int r = 0; r < 6; r++) {
            int move_to[2] = {from + dice[r], from - dice[r]};
            for (int i = 0; i < 2; i++) {
                int position = move_to[i] + N[move_to[i]];
                if (isPositionValid(position) && path[position] > path[from] + 1) {
                    path[position] = path[from] + 1;
                    q.push(position);
                }
            }
        }
    }
}

int main() {
    cin >> M;
    for (int r = 0; r < 6; r++)
        cin >> dice[r];
    cin >> start >> goal;
    start--, goal--;
    for (int m = 0; m < M; m++)
        cin >> N[m];

    MakePath();

    int position = start;
    for (int t = 0; t < MAX_T; t++) {
        if (position == goal)
            break;
        int r;
        cin >> r;
        int d = dice[r - 1];
        int output;
        if (path[position + d] < path[position]) {
            position += d;
            output = 1;
        }
        else if (path[position - d] < path[position]) {
            position -= d;
            output = -1;
        }
        else
            output = 0;

        cout << output << endl;
    }
    return 0;
}