#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct HashSet {
    int size;
    Node** buckets;
} HashSet;

HashSet* createHashSet(int size) {
    HashSet* set = (HashSet*) malloc(sizeof(HashSet));
    set->size = size;
    set->buckets = (Node**) calloc(size, sizeof(Node*));
    return set;
}

int hashFunction(int data, int size) {
    return abs(data) % size;
}

void insert(HashSet* set, int data) {
    int index = hashFunction(data, set->size);
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = set->buckets[index];
    set->buckets[index] = newNode;
}

int contains(HashSet* set, int data) {
    int index = hashFunction(data, set->size);
    Node* curr = set->buckets[index];
    while (curr != NULL) {
        if (curr->data == data) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void freeHashSet(HashSet* set) {
    for (int i = 0; i < set->size; i++) {
        Node* curr = set->buckets[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(set->buckets);
    free(set);
}

int main() {
    int n, q, i, cnt = 0;
    scanf("%d", &n);

    HashSet* set = createHashSet(n);

    for (i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        insert(set, element);
    }

    scanf("%d", &q);

    for (i = 0; i < q; i++) {
        int element;
        scanf("%d", &element);
        if (contains(set, element)) {
            cnt++;
        }
    }

    printf("%d\n", cnt);

    freeHashSet(set);

    return 0;
}