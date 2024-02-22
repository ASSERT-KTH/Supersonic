#include <iostream>
#include <vector>

struct Node {
    int id;
    Node *parent;
    int depth;
    Node *leftMostChild;
    Node *rightSibling;
};

Node* initNode(int id) {
    Node* node = new Node;
    node->id = id;
    node->parent = nullptr;
    node->depth = (id == -1) ? 0 : -1;
    node->leftMostChild = nullptr;
    node->rightSibling = nullptr;
    return node;
}

void assignParentChild(Node* parent, Node* child) {
    child->parent = parent;
    child->depth = parent->depth + 1;
    if (parent->leftMostChild == nullptr) {
        parent->leftMostChild = child;
    } else {
        Node* sibling = parent->leftMostChild;
        while (sibling->rightSibling != nullptr) {
            sibling = sibling->rightSibling;
        }
        sibling->rightSibling = child;
    }
}

void printNode(Node* node) {
    std::cout << "node " << node->id << ": ";
    if (node->parent != nullptr) {
        std::cout << "parent = " << node->parent->id << ", ";
    } else {
        std::cout << "parent = -1, ";
    }
    std::cout << "depth = " << node->depth << ", ";
    if (node->parent == nullptr) {
        std::cout << "root";
    } else if (node->leftMostChild == nullptr) {
        std::cout << "leaf";
    } else {
        std::cout << "internal node";
    }
    std::cout << ", [";
    Node* child = node->leftMostChild;
    while (child != nullptr) {
        std::cout << child->id;
        if (child->rightSibling != nullptr) {
            std::cout << ", ";
        }
        child = child->rightSibling;
    }
    std::cout << "]\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = initNode(i);
    }
    for (int i = 0; i < n; i++) {
        int id, k;
        std::cin >> id >> k;
        for (int j = 0; j < k; j++) {
            int child_id;
            std::cin >> child_id;
            assignParentChild(nodes[id], nodes[child_id]);
        }
    }
    for (Node* node : nodes) {
        printNode(node);
    }
    return 0;
}