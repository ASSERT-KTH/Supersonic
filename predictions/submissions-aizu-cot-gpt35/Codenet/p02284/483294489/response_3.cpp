#include <cstdio>
#include <stack>
#include <string>

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z = new Node;
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    x = (k < x->key) ? x->left : x->right;
  }

  z->parent = y;
  if (y == NIL) {
    root = z;
  } else if (k < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }
}

bool find(int k) {
  Node *v = root;
  while (v != NIL) {
    if (k < v->key) {
      v = v->left;
    } else if (k > v->key) {
      v = v->right;
    } else {
      return true;
    }
  }
  return false;
}

void inorder(Node *u) {
  std::stack<Node*> stack;
  while (u != NIL || !stack.empty()) {
    if (u != NIL) {
      stack.push(u);
      u = u->left;
    } else {
      u = stack.top();
      stack.pop();
      printf(" %d", u->key);
      u = u->right;
    }
  }
}

void preorder(Node *u) {
  std::stack<Node*> stack;
  stack.push(u);

  while (!stack.empty()) {
    u = stack.top();
    stack.pop();
    printf(" %d", u->key);

    if (u->right != NIL) {
      stack.push(u->right);
    }
    if (u->left != NIL) {
      stack.push(u->left);
    }
  }
}

int main() {
  int n, x;
  std::string com;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    std::cin >> com;
    if (com == "insert") {
      scanf("%d", &x);
      insert(x);
    } else if (com == "print") {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    } else if (com == "find") {
      scanf("%d", &x);
      if (find(x)) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }

  return 0;
}