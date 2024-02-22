#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct HashSet {
    Node** bucket;
    int size;
} HashSet;

HashSet* createHashSet(int size) {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    set->size = size;
    set->bucket = (Node**)calloc(size, sizeof(Node*));
    return set;
}

void insert(HashSet* set, int val) {
    int hash = abs(val) % set->size;
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = set->bucket[hash];
    set->bucket[hash] = node;
}

bool contains(HashSet* set, int val) {
    int hash = abs(val) % set->size;
    Node* node = set->bucket[hash];
    while (node != NULL) {
        if (node->val == val) {
            return true;
        }
        node = node->next;
    }
    return false;
}

int main() {
    int i, k, n, q, C = 0;
    scanf("%d", &n);

    HashSet* set = createHashSet(n);
    for (i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insert(set, val);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        int val;
        scanf("%d", &val);
        if (contains(set, val)) {
            C++;
        }
    }

    printf("%d\n", C);
    return 0;
}