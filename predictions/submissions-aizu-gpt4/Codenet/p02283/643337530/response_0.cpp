#include <iostream>

struct Node {
  int key;
  Node *right = nullptr, *left = nullptr;
};

Node *root = nullptr;

Node* newNode(int item)
{
    Node* temp = new Node;
    temp->key = item;
    return temp;
}

Node* insert(Node* node, int key)
{
    if (node == nullptr) return newNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    return node;
}

void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        std::cout << " " << root->key;
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != nullptr)
    {
        std::cout << " " << root->key;
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int n, x;
    std::string command;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> command;
        if (command == "insert")
        {
            std::cin >> x;
            root = insert(root, x);
        }
        else if (command == "print")
        {
            inorder(root);
            std::cout << "\n";
            preorder(root);
            std::cout << "\n";
        }
    }
    return 0;
}