#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100

// Hash set data structure
typedef struct {
    int data[MAX_N];
    int size;
} HashSet;

// Initialize a hash set
void initHashSet(HashSet* set) {
    set->size = 0;
}

// Add an element to the hash set
void addToHashSet(HashSet* set, int element) {
    set->data[set->size++] = element;
}

// Check if an element exists in the hash set
bool existsInHashSet(HashSet* set, int element) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == element) {
            return true;
        }
    }
    return false;
}

int main() {
    int i, n, q, element, C = 0;
    HashSet S, T;

    scanf("%d", &n);
    initHashSet(&S);
    for (i = 0; i < n; i++) {
        scanf("%d", &element);
        addToHashSet(&S, element);
    }

    scanf("%d", &q);
    initHashSet(&T);
    for (i = 0; i < q; i++) {
        scanf("%d", &element);
        addToHashSet(&T, element);
    }

    for (i = 0; i < T.size; i++) {
        if (existsInHashSet(&S, T.data[i])) {
            C++;
        }
    }

    printf("%d\n", C);
    return 0;
}