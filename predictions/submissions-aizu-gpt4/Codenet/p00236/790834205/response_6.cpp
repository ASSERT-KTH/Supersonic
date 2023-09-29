#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_set>
using namespace std;

constexpr int N = 49;
constexpr int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
constexpr int NIL = -1;
int w, h;
vector<vector<int>> field;
int size;
vector<vector<int>> vertex;
vector<vector<int>> edge;
bitset<N> visited;
unordered_set<unsigned long long> memo;

inline void make_graph() {
    size = 0;
    vertex.assign(h, vector<int>(w, NIL));
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            if (!field[y][x])
                vertex[y][x] = size++;
    edge.assign(h * w, vector<int>());
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x) {
            if (vertex[y][x] == NIL)
                continue;
            for (const auto &d : NEXT) {
                int ny = y + d[0];
                int nx = x + d[1];
                if (ny < 0 || h <= ny || nx < 0 || w <= nx)
                    continue;
                if (vertex[ny][nx] == NIL)
                    continue;
                edge[vertex[y][x]].push_back(vertex[ny][nx]);
            }
        }
}

inline void reachability(const int &from, bitset<N> &visited) {
    visited.set(from);
    for (const auto &to : edge[from])
        if (!visited.test(to))
            reachability(to, visited);
}

inline bool cut_vertex(const int &from) {
    auto dup = visited;
    dup.set(from);
    for (const auto &to : edge[from]) {
        if (dup[to])
            continue;
        reachability(to, dup);
        if (dup.count() != size)
            return true;
    }
    return false;
}

inline bool dfs(const int &start, int from) {
    unsigned long long m = visited.to_ullong() * N + from;
    if (memo.count(m))
        return false;
    memo.insert(m);
    if (cut_vertex(from))
        return false;
    for (int u = 0; u < size; ++u) {
        if (u == from || visited.test(u))
            continue;
        int degree = 0;
        for (const auto &v : edge[u])
            if (v == start || !visited.test(v))
                ++degree;
        if (degree < 2)
            return false;
    }
    visited.set(from);
    for (const auto &to : edge[from]) {
        if (to == start && visited.count() == size)
            return true;
        if (visited[to])
            continue;
        if (dfs(start, to))
            return true;
    }
    visited.reset(from);
    return false;
}

bool solve() {
    visited.reset();
    make_graph();
    memo.clear();
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            if (!field[y][x])
                return dfs(vertex[y][x], vertex[y][x]);
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> w >> h, w | h) {
        field.assign(h, vector<int>(w));
        for (auto &line : field)
            for (auto &v : line)
                cin >> v;
        cout << (solve() ? "Yes\n" : "No\n");
    }
    return 0;
}