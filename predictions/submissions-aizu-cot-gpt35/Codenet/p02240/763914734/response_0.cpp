#include <cstdio>
#include <vector>
#include <queue>

class Relation {
public:
    Relation(int tmp_n, int tmp_m) {
        n = tmp_n;
        m = tmp_m;
        V.resize(n);
        group.resize(n);
    }

    void push(int s, int t) {
        V[s].push_back(t);
        V[t].push_back(s);
    }

    void makeGroup() {
        int group_number = 1;
        std::vector<bool> visited(n, false);
        std::queue<int> Q;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                Q.push(i);
                group[i] = group_number;
                visited[i] = true;

                while (!Q.empty()) {
                    int node = Q.front();
                    Q.pop();

                    for (int neighbor : V[node]) {
                        if (!visited[neighbor]) {
                            Q.push(neighbor);
                            group[neighbor] = group_number;
                            visited[neighbor] = true;
                        }
                    }
                }

                group_number++;
            }
        }
    }

    bool canAccess(int s, int t) {
        return group[s] == group[t];
    }

private:
    std::vector<std::vector<int>> V;
    std::vector<int> group;
    int n, m;
};

int main() {
    int n, m, s, t, q;
    std::scanf("%d %d", &n, &m);
    Relation relation(n, m);

    for (int i = 0; i < m; i++) {
        std::scanf("%d %d", &s, &t);
        relation.push(s, t);
    }

    relation.makeGroup();

    std::scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        std::scanf("%d %d", &s, &t);
        if (relation.canAccess(s, t)) {
            std::printf("yes\n");
        } else {
            std::printf("no\n");
        }
    }

    return 0;
}