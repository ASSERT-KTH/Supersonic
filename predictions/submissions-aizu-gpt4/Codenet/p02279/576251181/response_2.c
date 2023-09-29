#include <cstdio>
#include <vector>
using namespace std;
struct Node {
    int id;
    Node *parent;
    vector<Node *> children;
};
Node *makeNode(int id) {
    Node *node = new Node;
    node->id = id;
    node->parent = nullptr;
    return node;
}
int getDepth(Node *node) {
    int depth = 0;
    for (; node->parent != nullptr; node = node->parent)
        ++depth;
    return depth;
}
void printNode(Node *node) {
    printf("node %d: ", node->id);
    if (node->parent != nullptr)
        printf("parent = %d, ", node->parent->id);
    else
        printf("parent = -1, ");
    printf("depth = %d, ", getDepth(node));
    if (node->parent == nullptr)
        printf("root, ");
    else if (node->children.empty())
        printf("leaf, ");
    else
        printf("internal node, ");
    printf("[");
    if (!node->children.empty()) {
        printf("%d", node->children[0]->id);
        for (size_t i = 1; i < node->children.size(); ++i)
            printf(", %d", node->children[i]->id);
    }
    printf("]\n");
}
int main() {
    int n;
    scanf("%d", &n);
    vector<Node *> nodes(n);
    for (int i = 0; i < n; ++i)
        nodes[i] = makeNode(i);
    for (int i = 0; i < n; ++i) {
        int id, k;
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; ++j) {
            int c;
            scanf("%d", &c);
            nodes[id]->children.push_back(nodes[c]);
            nodes[c]->parent = nodes[id];
        }
    }
    for (auto node : nodes)
        printNode(node);
    for (auto node : nodes)
        delete node;
    return 0;
}