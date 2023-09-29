#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

class Relation {
public:
    int n;
    vector<vector<int>> graph;
    vector<int> group;

    Relation(int n) : n(n), graph(n), group(n) {}

    void addRelation(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void assignGroups() {
        int group_id = 0;
        for(int i = 0; i < n; ++i) {
            if (group[i] != 0) continue;
            queue<int> q;
            group[i] = ++group_id;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto& adj : graph[node]) {
                    if (group[adj] == 0) {
                        group[adj] = group_id;
                        q.push(adj);
                    }
                }
            }
        }
    }

    bool canAccess(int a, int b) {
        return group[a] == group[b];
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Relation relation(n);
    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        relation.addRelation(a, b);
    }
    relation.assignGroups();
    int q;
    scanf("%d", &q);
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf(relation.canAccess(a, b) ? "yes\n" : "no\n");
    }
    return 0;
}