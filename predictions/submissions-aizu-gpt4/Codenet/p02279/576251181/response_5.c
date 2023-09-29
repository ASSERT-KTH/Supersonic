#include <iostream>
#include <vector>
#include <memory>

struct Node {
    int id;
    std::shared_ptr<Node> parent;
    std::shared_ptr<Node> leftMostChild;
    std::shared_ptr<Node> rightSibling;
    Node(int id) : id(id), parent(nullptr), leftMostChild(nullptr), rightSibling(nullptr) {}
};

using NodePtr = std::shared_ptr<Node>;

int getDepth(NodePtr node) {
    int depth = 0;
    for (; node->parent != nullptr; node = node->parent)
        depth++;
    return depth;
}

void printType(NodePtr node) {
    if (node->parent == nullptr)
        std::cout << "root";
    else if (node->leftMostChild == nullptr)
        std::cout << "leaf";
    else
        std::cout << "internal node";
}

void printChild(NodePtr node) {
    std::cout << "[";
    if (node->leftMostChild != nullptr) {
        node = node->leftMostChild;
        std::cout << node->id;
        while (node->rightSibling != nullptr) {
            node = node->rightSibling;
            std::cout << ", " << node->id;
        }
    }
    std::cout << "]";
}

void printNode(NodePtr node) {
    std::cout << "node " << node->id << ": ";
    if (node->parent != nullptr)
        std::cout << "parent = " << node->parent->id << ", ";
    else
        std::cout << "parent = -1, ";
    std::cout << "depth = " << getDepth(node) << ", ";
    printType(node);
    std::cout << ", ";
    printChild(node);
    std::cout << "\n";
}

int main() {
    int n;
    int id;
    int k;
    int c1, c2;
    NodePtr head = std::make_shared<Node>(-1);
    std::cin >> n;
    std::vector<NodePtr> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = std::make_shared<Node>(i);
    for (int i = 0; i < n; i++) {
        std::cin >> id >> k;
        for (int j = 0; j < k; j++) {
            std::cin >> c1;
            if (j == 0) {
                arr[id]->leftMostChild = arr[c1];
            } else {
                arr[c2]->rightSibling = arr[c1];
            }
            arr[c1]->parent = arr[id];
            c2 = c1;
        }
    }
    for (int i = 0; i < n; i++)
        printNode(arr[i]);
    return 0;
}