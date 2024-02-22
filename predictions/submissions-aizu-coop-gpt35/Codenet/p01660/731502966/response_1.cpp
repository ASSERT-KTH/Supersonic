#include <iostream>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], *N;

bool isPositionValid(int p) { return 0 <= p && p < M; }

int *MakePath(int *path, int from)
{
    static bool visit[MAX_M] = {};

    static auto checkPath = [&path](int moveto) -> int {
        if (!isPositionValid(moveto))
            return 2 * MAX_T;
        else {
            int position = moveto + N[moveto];
            if (!visit[position])
                MakePath(path, position);
            return path[position] + 1;
        }
    };

    static auto tryMove = [&path](int moveto, int path_before, int &position) -> bool {
        if (isPositionValid(moveto)) {
            if (path_before > path[moveto + N[moveto]]) {
                position = moveto + N[moveto];
                return true;
            }
        }
        return false;
    };

    if (path == NULL) {
        path = new int[M];
        for (int m = 0; m < M; m++)
            path[m] = MAX_T + 1;
    }
    visit[from] = true;
    int bestpath = MAX_T;
    if (from == goal)
        bestpath = 0;
    else {
        // Loop unrolling for dice rolls
        bestpath = checkPath(from + dice[0]);
        bestpath = min(bestpath, checkPath(from - dice[0]));
        bestpath = min(bestpath, checkPath(from + dice[1]));
        bestpath = min(bestpath, checkPath(from - dice[1]));
        bestpath = min(bestpath, checkPath(from + dice[2]));
        bestpath = min(bestpath, checkPath(from - dice[2]));
        bestpath = min(bestpath, checkPath(from + dice[3]));
        bestpath = min(bestpath, checkPath(from - dice[3]));
        bestpath = min(bestpath, checkPath(from + dice[4]));
        bestpath = min(bestpath, checkPath(from - dice[4]));
        bestpath = min(bestpath, checkPath(from + dice[5]));
        bestpath = min(bestpath, checkPath(from - dice[5]));
    }
    path[from] = bestpath;
    return path;
}

int main()
{
    cin >> M;
    for (int r = 0; r < 6; r++)
        cin >> dice[r];
    cin >> start >> goal;
    start--, goal--;
    N = new int[M];
    for (int m = 0; m < M; m++)
        cin >> N[m];
    int path[MAX_M]; // Change to static array
    for (int m = 0; m < M; m++)
        path[m] = MAX_T + 1;

    // Call MakePath function directly without allocating memory
    MakePath(path, start);

    int position = start;
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

    delete[] N;
    return 0;
}