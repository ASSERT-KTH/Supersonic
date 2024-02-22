#include <cstdio>

struct Node {
  int key;
  Node *parent, *left, *right;
};
Node *root, *NIL;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z = new Node{k, NIL, NIL, NIL};

  while (x != NIL) {
    y = x;
    z->key < x->key ? x = x->left : x = x->right;
  }

  z->parent = y;

  if (y == NIL) {
    root = z;
  } else {
    z->key < y->key ? y->left = z : y->right = z;
  }
}

bool find(int k) {
  for (Node *v = root; v != NIL; k < v->key ? v = v->left : v = v->right) {
    if (k == v->key)
      return true;
  }
  return false;
}

void inorder(Node *u) {
  if (u == NIL)
    return;
  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}

void preorder(Node *u) {
  if (u == NIL)
    return;
  printf(" %d", u->key);
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n, x, com;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &com);
    switch (com) {
      case 1:  // insert
        scanf("%d", &x);
        insert(x);
        break;
      case 2:  // print
        inorder(root);
        printf("\n");
        preorder(root);
        printf("\n");
        break;
      case 3:  // find
        scanf("%d", &x);
        printf(find(x) ? "yes\n" : "no\n");
        break;
    }
  }
  return 0;
}