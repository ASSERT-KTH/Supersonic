#include <stdio.h>
#include <vector>
using namespace std;
struct node {
    int id, parent, depth;
    vector<int> child;
};
vector<node> tree;
void setDepth(int id) {
    if (tree[id].parent != -1)
        tree[id].depth = tree[tree[id].parent].depth + 1;
    for (auto child : tree[id].child)
        setDepth(child);
}
int main() {
    int n, id, k, c;
    scanf("%d", &n);
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        tree[i].parent = -1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &c);
            tree[id].child.push_back(c);
            tree[c].parent = id;
        }
    }
    for (int i = 0; i < n; i++) {
        if (tree[i].parent == -1) {
            tree[i].depth = 0;
            setDepth(i);
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("node %d: parent = %d, depth = %d, ", i, tree[i].parent, tree[i].depth);
        if (tree[i].parent == -1)
            printf("root, ");
        else if (tree[i].child.empty())
            printf("leaf, ");
        else
            printf("internal node, ");
        printf("[");
        for (int j = 0; j < tree[i].child.size(); j++) {
            if (j) printf(", ");
            printf("%d", tree[i].child[j]);
        }
        printf("]\n");
    }
    return 0;
}