#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int id;
    Node *parent = nullptr;
    vector<Node*> children;
};

int main() {
    int n;
    cin >> n;
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        int id, k;
        cin >> id >> k;
        nodes[id].id = id;
        nodes[id].children.resize(k);
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            nodes[c].parent = &nodes[id];
            nodes[id].children[j] = &nodes[c];
        }
    }
    for (auto &node : nodes) {
        cout << "node " << node.id << ": ";
        if (node.parent != nullptr)
            cout << "parent = " << node.parent->id << ", ";
        else
            cout << "parent = -1, ";
        int depth = 0;
        for (Node *p = &node; p->parent != nullptr; p = p->parent)
            depth++;
        cout << "depth = " << depth << ", ";
        if (node.parent == nullptr)
            cout << "root";
        else if (node.children.empty())
            cout << "leaf";
        else
            cout << "internal node";
        cout << ", [";
        for (int i = 0; i < node.children.size(); i++) {
            if (i > 0) cout << ", ";
            cout << node.children[i]->id;
        }
        cout << "]\n";
    }
    return 0;
}