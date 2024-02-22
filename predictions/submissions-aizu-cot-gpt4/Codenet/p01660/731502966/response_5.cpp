#include <iostream>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], N[MAX_M], path[MAX_M];
bool visit[MAX_M] = {};

auto checkPath = [](int moveto) -> int {
    if (0 <= moveto && moveto < M) {
        int position = moveto + N[moveto];
        if (!visit[position])
            MakePath(path, position);
        return path[position] + 1;
    }
    return 2 * MAX_T;
};

int *MakePath(int from) {
    if (from == start) {
        for (int m = 0; m < M; m++)
            path[m] = MAX_T + 1;
    }
    visit[from] = true;
    int bestpath = MAX_T;
    if (from == goal)
        bestpath = 0;
    else {
        for (int r = 0; r < 6; r++) {
            bestpath = min(bestpath, checkPath(from + dice[r]));
            bestpath = min(bestpath, checkPath(from - dice[r]));
        }
    }
    path[from] = bestpath;
    return path;
}

int main() {
    cin >> M;
    for (int r = 0; r < 6; r++)
        cin >> dice[r];
    cin >> start >> goal;
    start--, goal--;

    for (int m = 0; m < M; m++)
        cin >> N[m];
    MakePath(start);
    int position = start;

    auto tryMove = [](int moveto, int path_before, int &position) -> bool {
        if (0 <= moveto && moveto < M) {
            if (path_before > path[moveto + N[moveto]]) {
                position = moveto + N[moveto];
                return true;
            }
        }
        return false;
    };

    for (int t = 0; t < MAX_T; t++) {
        if (position == goal)
            break;
        int r;
        cin >> r;
        int d = dice[r - 1];
        int output;
        if (tryMove(position + d, path[position], position))
            output = 1;
        else if (tryMove(position - d, path[position], position))
            output = -1;
        else
            output = 0;
        cout << output << endl;
    }
    return 0;
}