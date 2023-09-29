#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int b[2], f[2];
    bool v;
};

vector<Node> nodes;
int dfs(int s, int now, int maxi, int num) {
    nodes[now].v = true;
    for (int i = 0; i < 2; i++) {
        if (!nodes[nodes[now].b[i]].v) {
            if (maxi == nodes[now].f[i])
                num++;
            else if (maxi < nodes[now].f[i]) {
                maxi = nodes[now].f[i];
                num = 1;
            }
            if (nodes[now].b[i] == s)
                return num;
            return dfs(s, nodes[now].b[i], maxi, num);
        }
    }
    if (maxi == nodes[s].f[1])
        return num + 1;
    else if (maxi < nodes[s].f[1])
        return 1;
    else
        return num;
}

int main() {
    int n;
    while (cin >> n, n) {
        nodes.clear();
        nodes.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> nodes[i].b[0] >> nodes[i].f[0] >> nodes[i].b[1] >> nodes[i].f[1];
            nodes[i].v = false;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (!nodes[i].v) {
                nodes[i].v = true;
                ans = (ans * dfs(i, nodes[i].b[0], nodes[i].f[0], 1)) % 10007;
            }
        }
        cout << ans << endl;
    }
}