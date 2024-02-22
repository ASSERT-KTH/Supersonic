#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A simple hash function for integers
int hash(int key, int size) {
    return key % size;
}

// A simple set data structure for integers
typedef struct {
    int* data;
    int size;
    int capacity;
} Set;

// Initialize the set
Set* set_init(int capacity) {
    Set* set = (Set*)malloc(sizeof(Set));
    set->data = (int*)calloc(capacity, sizeof(int));
    set->size = 0;
    set->capacity = capacity;
    return set;
}

// Insert an element into the set
void set_insert(Set* set, int key) {
    int index = hash(key, set->capacity);
    set->data[index] = key;
    set->size++;
}

// Check if an element is in the set
bool set_contains(Set* set, int key) {
    int index = hash(key, set->capacity);
    return set->data[index] == key;
}

int main() {
    int i, n, q, C = 0;
    int* T;
    Set* S;

    // Read the size of S
    scanf("%d", &n);
    S = set_init(n);

    // Read the elements of S
    for (i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        set_insert(S, element);
    }

    // Read the size of T
    scanf("%d", &q);
    T = (int*)malloc(q * sizeof(int));

    // Read the elements of T
    for (i = 0; i < q; i++) {
        scanf("%d", &T[i]);
    }

    // Check if each element in T is in S
    for (i = 0; i < q; i++) {
        if (set_contains(S, T[i])) {
            C++;
        }
    }

    printf("%d\n", C);

    // Clean up
    free(S->data);
    free(S);
    free(T);
    return 0;
}