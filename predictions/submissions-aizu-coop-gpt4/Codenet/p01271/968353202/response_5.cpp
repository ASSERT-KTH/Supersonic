#include <unordered_map>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int lx, ly, rx, ry;
    Node(int lx, int ly, int rx, int ry) : lx(lx), ly(ly), rx(rx), ry(ry) {}
    bool operator==(const Node& other) const {
        return lx == other.lx && ly == other.ly && rx == other.rx && ry == other.ry;
    }
};

// Define a hash function for the Node struct.
struct NodeHash {
    size_t operator()(const Node& node) const {
        return node.lx ^ node.ly ^ node.rx ^ node.ry;
    }
};

using NodeMap = unordered_map<Node, bool, NodeHash>;

// Define the BFS function that uses the NodeMap instead of a 4D array.
bool bfs(int w, int h, string mp[2][51], NodeMap& visited, Node start) {
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<Node> Q;
    Q.push(start);

    while (!Q.empty()) {
        Node current = Q.front();
        Q.pop();

        int cnt = (mp[0][current.ly][current.lx] == '%') + (mp[1][current.ry][current.rx] == '%');
        if (cnt == 2) return true;
        if (visited[current] || cnt == 1) continue;
        visited[current] = true;

        for (auto& dir : directions) {
            int nlx = current.lx + dir.first, nly = current.ly + dir.second;
            int nrx = current.rx - dir.first, nry = current.ry + dir.second;

            if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nly][nlx] == '#') {
                nlx = current.lx, nly = current.ly;
            }

            if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nry][nrx] == '#') {
                nrx = current.rx, nry = current.ry;
            }

            if (nlx != current.lx || nly != current.ly || nrx != current.rx || nry != current.ry) {
                Q.push(Node(nlx, nly, nrx, nry));
            }
        }
    }

    return false;
}

int main() {
    int w, h;
    string mp[2][51];

    while (cin >> w >> h && w && h) {
        for (int i = 0; i < h; ++i) {
            cin >> mp[0][i] >> mp[1][i];
        }

        int lx, ly, rx, ry;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (mp[0][i][j] == 'L') lx = j, ly = i;
                if (mp[1][i][j] == 'R') rx = j, ry = i;
            }
        }

        NodeMap visited;
        if (bfs(w, h, mp, visited, Node(lx, ly, rx, ry))) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}