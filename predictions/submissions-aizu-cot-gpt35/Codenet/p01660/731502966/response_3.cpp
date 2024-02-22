#include <iostream>

#define isPositionValid(p) (0 <= (p) && (p) < M)

const int MAX_T = 3000;
const int MAX_M = 300;

int M, start, goal, dice[6], N[MAX_M];

int* MakePath(int* path, int from) {
    bool visit[MAX_M] = {};
    auto checkPath = [&path](int moveto) -> int {
        if (!isPositionValid(moveto))
            return 2 * MAX_T;
        else {
            int position = moveto + N[moveto];
            if (!visit[position])
                MakePath(path, position);
            return path[position] + 1;
        }
    };

    if (path == nullptr) {
        static int path[MAX_M];
        for (int m = 0; m < M; m++)
            path[m] = MAX_T + 1;
        path[from] = 0;
        return path;
    }

    visit[from] = true;
    int bestpath = MAX_T;
    if (from == goal)
        bestpath = 0;
    else {
        for (int r = 0; r < 6; r++) {
            bestpath = std::min(bestpath, checkPath(from + dice[r]));
            bestpath = std::min(bestpath, checkPath(from - dice[r]));
        }
    }
    path[from] = bestpath;
    return path;
}

bool tryMove(int moveto, int path_before, int& position) {
    if (isPositionValid(moveto)) {
        if (path_before > path[moveto + N[moveto]]) {
            position = moveto + N[moveto];
            return true;
        }
    }
    return false;
}

int main() {
    std::cin >> M;
    for (int r = 0; r < 6; r++)
        std::cin >> dice[r];
    std::cin >> start >> goal;
    start--, goal--;

    for (int m = 0; m < M; m++)
        std::cin >> N[m];

    int* path = MakePath(nullptr, start);
    int position = start;

    for (int t = 0; t < MAX_T; t++) {
        if (position == goal)
            break;
        int r;
        std::cin >> r;
        int d = dice[r - 1];
        int output;
        if (tryMove(position + d, path[position], position))
            output = 1;
        else if (tryMove(position - d, path[position], position))
            output = -1;
        else
            output = 0;
        std::cout << output << std::endl;
    }

    return 0;
}