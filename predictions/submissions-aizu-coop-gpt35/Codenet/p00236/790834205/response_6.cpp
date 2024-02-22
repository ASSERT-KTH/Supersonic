#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 49;
int w, h;
vector<vector<int>> field;
int size;
vector<vector<int>> vertex;
vector<vector<int>> edge;
vector<bool> visited;
vector<bool> cutVertex;

void make_graph() {
    enum { Y, X };
    const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    size = 0;
    vertex.clear();
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (!field[y][x]) {
                vertex.push_back({y, x});
                ++size;
            }
        }
    }
    edge = vector<vector<int>>(size, vector<int>());
    for (int i = 0; i < size; ++i) {
        int y = vertex[i][Y];
        int x = vertex[i][X];
        for (const auto &d : NEXT) {
            int ny = y + d[Y];
            int nx = x + d[X];
            if (ny < 0 || h <= ny || nx < 0 || w <= nx)
                continue;
            for (int j = 0; j < size; ++j) {
                if (vertex[j][Y] == ny && vertex[j][X] == nx) {
                    edge[i].push_back(j);
                    break;
                }
            }
        }
    }
}

void reachability(const int &from) {
    visited[from] = true;
    for (const auto &to : edge[from]) {
        if (!visited[to]) {
            reachability(to);
        }
    }
}

bool dfs(const int &start, int from, int degree) {
    if (cutVertex[from]) {
        return false;
    }
    visited[from] = true;

    if (degree < 2) {
        return false;
    }

    for (const auto &to : edge[from]) {
        if (to == start && visited.count() == size) {
            return true;
        }
        if (!visited[to] && dfs(start, to, degree - 1)) {
            return true;
        }
    }

    visited[from] = false;
    return false;
}

bool solve() {
    visited = vector<bool>(size, false);
    make_graph();
    cutVertex = vector<bool>(size, false);

    for (int i = 0; i < size; ++i) {
        visited.assign(size, false);
        reachability(i);
        cutVertex[i] = visited.count() != size;
    }

    visited.assign(size, false);
    for (int i = 0; i < size; ++i) {
        int degree = 0;
        for (const auto &to : edge[i]) {
            if (to == i || !visited[to]) {
                ++degree;
            }
        }
        if (dfs(i, i, degree)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> w >> h, w | h) {
        field = vector<vector<int>>(h, vector<int>(w));
        for (auto &line : field) {
            for (auto &v : line) {
                cin >> v;
            }
        }
        cout << (solve() ? "Yes" : "No") << endl;
    }

    return 0;
}