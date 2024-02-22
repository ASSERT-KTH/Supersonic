#include <cstdio>
using namespace std;
struct Node {
  int key;
  Node *parent, *left, *right;
};
Node *root, *NIL;
void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  while (x != NIL) {
    y = x;
    if (k < x->key) {
      x = x->left;
    } else if (k > x->key) {
      x = x->right;
    } else {
      return; // Key already exists, no need to insert
    }
  }
  Node *z;
  z = new Node;
  z->key = k;
  z->left = NIL;
  z->right = NIL;
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
    if (k == v->key)
      return true;
    if (k < v->key) {
      v = v->left;
    } else {
      v = v->right;
    }
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
  int n, x;
  char com[20];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", com);
    if (com[0] == 'i') {
      scanf("%d", &x);
      insert(x);
    } else if (com[0] == 'p') {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    } else if (com[0] == 'f') {
      scanf("%d", &x);
      if (find(x))
        printf("yes\n");
      else
        printf("no\n");
    }
  }
  return 0;
}