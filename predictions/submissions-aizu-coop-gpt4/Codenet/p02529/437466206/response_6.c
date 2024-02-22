#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right;
} node;

node* new_node(int item) {
    node* temp = (node*)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* node, int key) {
    if (node == NULL) return new_node(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    return node;
}

int search(node* root, int key) {
    while (root != NULL) {
        if (key < root->key) root = root->left;
        else if (key > root->key) root = root->right;
        else return 1;
    }
    return 0;
}

int main() {
    int i, n, q, t, C = 0;
    node *root = NULL;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &t);
        root = insert(root, t);
    }
    
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &t);
        if (search(root, t)) {
            C++;
        }
    }
    printf("%d\n", C);
    return 0;
}