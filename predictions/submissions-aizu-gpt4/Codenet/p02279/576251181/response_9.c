#include <stdio.h>
#include <vector>

using namespace std;

struct Node {
    int id;
    Node* parent;
    Node* leftMostChild;
    Node* rightSibling;
};

Node* makeNode(int id) {
    Node* node = new Node;
    node->id = id;
    node->parent = NULL;
    node->leftMostChild = NULL;
    node->rightSibling = NULL;
    return node;
}

int getDepth(Node* node) {
    int depth = 0;
    while (node->parent) {
        node = node->parent;
        ++depth;
    }
    return depth;
}

void printNode(Node* node) {
    printf("node %d: ", node->id);
    printf("parent = %d, ", node->parent ? node->parent->id : -1);
    printf("depth = %d, ", getDepth(node));

    if (!node->parent) printf("root");
    else if (!node->leftMostChild) printf("leaf");
    else printf("internal node");

    printf(", [");
    if (node->leftMostChild) {
        node = node->leftMostChild;
        printf("%d", node->id);
        while (node->rightSibling) {
            node = node->rightSibling;
            printf(", %d", node->id);
        }
    }
    printf("]\n");
}

int main() {
    int n;
    scanf("%d", &n);

    vector<Node*> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = makeNode(i);
    }

    for (int i = 0; i < n; ++i) {
        int id, k;
        scanf("%d%d", &id, &k);

        Node* lastChild = NULL;
        for (int j = 0; j < k; ++j) {
            int childId;
            scanf("%d", &childId);
            nodes[childId]->parent = nodes[id];

            if (!j) nodes[id]->leftMostChild = nodes[childId];
            else lastChild->rightSibling = nodes[childId];

            lastChild = nodes[childId];
        }
    }

    for (auto node : nodes) {
        printNode(node);
        delete node;
    }

    return 0;
}