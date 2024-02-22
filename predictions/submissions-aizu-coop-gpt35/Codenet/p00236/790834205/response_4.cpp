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
vector<vector<bool>> memo;

void make_graph() {
    enum { Y, X };
    const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    const int NIL = -1;
    size = 0;
    vertex = vector<vector<int>>(h, vector<int>(w, NIL));
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            if (!field[y][x])
                vertex[y][x] = size++;
    edge = vector<vector<int>>(h * w, vector<int>());
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x) {
            if (vertex[y][x] == NIL)
                continue;
            for (const auto& d : NEXT) {
                int ny = y + d[Y];
                int nx = x + d[X];
                if (ny < 0 || h <= ny || nx < 0 || w <= nx)
                    continue;
                if (vertex[ny][nx] == NIL)
                    continue;
                edge[vertex[y][x]].push_back(vertex[ny][nx]);
            }
        }
}

void reachability(const int& from) {
    visited[from] = true;
    for (const auto& to : edge[from])
        if (!visited[to])
            reachability(to);
}

bool cut_vertex(const int& from) {
    visited[from] = true;
    bool isCutVertex = false;
    int unvisitedCount = 0;
    for (const auto& to : edge[from]) {
        if (!visited[to]) {
            unvisitedCount++;
            reachability(to);
            if (visited.count() != size) {
                isCutVertex = true;
                break;
            }
        }
    }
    visited[from] = false;
    return isCutVertex;
}

bool dfs(const int& start, int from, int unvisitedCount) {
    if (unvisitedCount > 2)
        return false;
    memo[start][from] = true;
    if (cut_vertex(from))
        return false;
    for (const auto& to : edge[from]) {
        if (to == start && unvisitedCount == 0)
            return true;
        if (!visited[to]) {
            visited[to] = true;
            int degree = 0;
            for (const auto& v : edge[to])
                if (v == start || !visited[v])
                    ++degree;
            if (degree < 2)
                continue;
            if (dfs(start, to, unvisitedCount - 1))
                return true;
            visited[to] = false;
        }
    }
    return false;
}

bool solve() {
    visited = vector<bool>(size, false);
    make_graph();
    memo = vector<vector<bool>>(size, vector<bool>(size, false));
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            if (!field[y][x])
                return dfs(vertex[y][x], vertex[y][x], size - 1);
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> w >> h, w | h) {
        field = vector<vector<int>>(h, vector<int>(w));
        for (auto& line : field)
            for (auto& v : line)
                cin >> v;
        cout << (solve() ? "Yes" : "No") << endl;
    }

    return 0;
}