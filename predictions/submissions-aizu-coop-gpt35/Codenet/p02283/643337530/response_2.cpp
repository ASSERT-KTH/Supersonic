#include <cstdio>
#include <cstdlib>
using std::cout; // Step 1: Replace 'using namespace std;' with 'using std::cout;'

struct Node {
  int key;
  Node* right, *left, *parent;
};

Node* root = nullptr; // Step 3: Replace 'NIL' with 'nullptr'
Node* NIL = nullptr;  // Step 3: Replace 'NIL' with 'nullptr'

void insert(int& k) { // Step 5: Modify the 'insert' function to take the key parameter by reference
  Node* y = NIL;
  Node* x = root;
  Node* z = new Node(); // Step 4: Replace 'malloc' with 'new'
  z->key = k;
  z->left = NIL;
  z->right = NIL;
  while (x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == NIL) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void inorder(Node* u) {
  if (u == NIL)
    return;
  inorder(u->left);
  cout << " " << u->key; // Step 7: Replace 'printf' with 'cout'
  inorder(u->right);
}

void preorder(Node* u) {
  if (u == NIL)
    return;
  cout << " " << u->key; // Step 7: Replace 'printf' with 'cout'
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n, i, x;
  std::string com; // Step 2: Remove unnecessary 'string' header
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    std::cin >> com; // Step 6: Modify 'com' string parameter to be passed as a const reference
    if (com == "insert") {
      scanf("%d", &x);
      insert(x);
    } else if (com == "print") {
      inorder(root);
      cout << "\n"; // Step 7: Replace 'printf' with 'cout'
      preorder(root);
      cout << "\n"; // Step 7: Replace 'printf' with 'cout'
    }
  }
  return 0;
}