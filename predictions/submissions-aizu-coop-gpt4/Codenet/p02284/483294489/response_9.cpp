#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

enum CommandType { INSERT, PRINT, FIND };

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;
vector<Node> mempool;
int memptr = 0;

Node* alloc_node() {
  return &mempool[memptr++];
}

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z = alloc_node();
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
    if (z->key < y->key)
      y->left = z;
    else
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
  mempool.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%s", com);
    CommandType command;
    if (strcmp(com, "insert") == 0)
      command = INSERT;
    else if (strcmp(com, "print") == 0)
      command = PRINT;
    else if (strcmp(com, "find") == 0)
      command = FIND;

    switch (command) {
    case INSERT:
      scanf("%d", &x);
      insert(x);
      break;
    case PRINT:
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
      break;
    case FIND:
      scanf("%d", &x);
      if (find(x))
        printf("yes\n");
      else
        printf("no\n");
      break;
    }
  }
  return 0;
}