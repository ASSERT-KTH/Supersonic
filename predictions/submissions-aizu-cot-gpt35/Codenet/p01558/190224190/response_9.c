#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 300010
#define MAX_HASH 2000010

typedef struct Node {
  int hash;
  struct Node* left;
  struct Node* right;
} Node;

unsigned long djb2_hash(char* str) {
  unsigned long hash = 5381;
  int c;
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c;
  return hash;
}

Node* create_node(int hash) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->hash = hash;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* insert(Node* root, int hash) {
  if (root == NULL)
    return create_node(hash);
  if (hash < root->hash)
    root->left = insert(root->left, hash);
  else if (hash > root->hash)
    root->right = insert(root->right, hash);
  return root;
}

Node* find(Node* root, int hash) {
  if (root == NULL || root->hash == hash)
    return root;
  if (hash < root->hash)
    return find(root->left, hash);
  return find(root->right, hash);
}

void hin(Node** root, int hash) {
  *root = insert(*root, hash);
}

Node* minValueNode(Node* node) {
  Node* current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

Node* deleteNode(Node* root, int hash) {
  if (root == NULL)
    return root;
  if (hash < root->hash)
    root->left = deleteNode(root->left, hash);
  else if (hash > root->hash)
    root->right = deleteNode(root->right, hash);
  else {
    if (root->left == NULL) {
      Node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node* temp = root->left;
      free(root);
      return temp;
    }
    Node* temp = minValueNode(root->right);
    root->hash = temp->hash;
    root->right = deleteNode(root->right, temp->hash);
  }
  return root;
}

void init_hash(char* str, unsigned long* hashes, int len) {
  int i;
  for (i = 0; i < len; i++) {
    hashes[i] = djb2_hash(str + i);
  }
}

int main() {
  int n = 0, m, a, b, i, l = 0, r = 1;
  char s[MAX_LEN], q[5];
  Node* hash_tree = NULL;
  unsigned long hashes[MAX_LEN];
  
  scanf("%*d %d %s", &m, s);
  init_hash(s, hashes, strlen(s));
  
  for (i = 0; i < m; i++) {
    scanf("%s", q);
    if (q[0] == 'L')
      l += q[1] - '-' ? 1 : -1;
    else
      r += q[1] - '-' ? 1 : -1;

    int hash1 = hashes[r] - hashes[l] * 1L;
    unsigned long hash2 = hashes[r] - hashes[l] * 1UL;
    
    Node* node = find(hash_tree, hash1);
    if (node == NULL) {
      hin(&hash_tree, hash1);
      hin(&hash_tree, hash2);
    } else {
      int found = 0;
      while (node != NULL) {
        if (node->hash == hash2) {
          found = 1;
          break;
        }
        node = node->right;
      }
      if (!found) {
        hin(&hash_tree, hash2);
      }
    }
  }
  
  a = hash_tree->hash;
  Node* temp = hash_tree;
  hash_tree = deleteNode(hash_tree, a);
  
  while (hash_tree != NULL) {
    b = hash_tree->hash;
    if (b == a)
      n++;
    a = b;
    hash_tree = deleteNode(hash_tree, a);
  }
  
  printf("%d\n", m - n);
  return 0;
}