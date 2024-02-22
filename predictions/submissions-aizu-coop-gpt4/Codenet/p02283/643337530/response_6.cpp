#include <cstdio>
#include <vector>
using namespace std;

#define MAX_NODES 500000
#define CMD_SIZE 10

struct Node {
  int key;
  Node *right, *left;
};

Node *root, *NIL;
Node pool[MAX_NODES];
int poolIdx = 0;
vector<int> inorderRes, preorderRes;
bool isModified = false;

Node* allocNode(int key) {
  Node* node = &pool[poolIdx++];
  node->key = key;
  node->left = NIL;
  node->right = NIL;
  return node;
}

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z = allocNode(k);
  while (x != NIL) {
    y = x;
    x = (z->key < x->key) ? x->left : x->right;
  }
  if (y == NIL) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
  isModified = true;
}

void inorder(Node *u) {
  if (u == NIL)
    return;
  inorder(u->left);
  inorderRes.push_back(u->key);
  inorder(u->right);
}

void preorder(Node *u) {
  if (u == NIL)
    return;
  preorderRes.push_back(u->key);
  preorder(u->left);
  preorder(u->right);
}

void print() {
  if (isModified) {
    inorderRes.clear();
    preorderRes.clear();
    inorder(root);
    preorder(root);
    isModified = false;
  }
  for (int key : inorderRes)
    printf(" %d", key);
  printf("\n");
  for (int key : preorderRes)
    printf(" %d", key);
  printf("\n");
}

int main() {
  int n, x;
  char com[CMD_SIZE];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", com);
    if (strcmp(com, "insert") == 0) {
      scanf("%d", &x);
      insert(x);
    } else if (strcmp(com, "print") == 0) {
      print();
    }
  }
  return 0;
}