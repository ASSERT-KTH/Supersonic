#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int next[2], val[2];
    bool visited;
};

vector<Node> nodes;
vector<int> visited;

int dfs(int s, int now, int maxi, int num) {
    nodes[now].visited = true;
    for (int i = 0; i < 2; i++) {
        if (!nodes[nodes[now].next[i]].visited) {
            if (maxi == nodes[now].val[i])
                num++;
            else if (maxi < nodes[now].val[i]) {
                maxi = nodes[now].val[i];
                num = 1;
            }
            if (nodes[now].next[i] == s)
                return num;
            return dfs(s, nodes[now].next[i], maxi, num);
        }
    }
    if (maxi == nodes[s].val[1])
        return num + 1;
    else if (maxi < nodes[s].val[1])
        return 1;
    else
        return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    int n;
    while (cin >> n, n) {
        nodes.resize(n);
        visited.assign(n, false);
        for (int i = 0; i < n; i++) {
            cin >> nodes[i].next[0] >> nodes[i].val[0] >> nodes[i].next[1] >> nodes[i].val[1];
            nodes[i].visited = false;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (!nodes[i].visited) {
                nodes[i].visited = true;
                ans = (ans * dfs(i, nodes[i].next[0], nodes[i].val[0], 1)) % 10007;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}