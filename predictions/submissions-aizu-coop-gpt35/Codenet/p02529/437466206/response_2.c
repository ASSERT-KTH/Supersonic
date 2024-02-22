#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashEntry;

typedef struct {
    int size;
    int capacity;
    HashEntry* entries;
} HashSet;

HashSet* createHashSet(int capacity) {
    HashSet* set = malloc(sizeof(HashSet));
    set->size = 0;
    set->capacity = capacity;
    set->entries = malloc(capacity * sizeof(HashEntry));
    return set;
}

void destroyHashSet(HashSet* set) {
    free(set->entries);
    free(set);
}

int hash(int key, int capacity) {
    return key % capacity;
}

void insert(HashSet* set, int key) {
    int index = hash(key, set->capacity);
    while (set->entries[index].value != 0) {
        index = (index + 1) % set->capacity;
    }
    set->entries[index].key = key;
    set->entries[index].value = 1;
    set->size++;
}

int contains(HashSet* set, int key) {
    int index = hash(key, set->capacity);
    while (set->entries[index].value != 0) {
        if (set->entries[index].key == key) {
            return 1;
        }
        index = (index + 1) % set->capacity;
    }
    return 0;
}

int main() {
    int i, n, q, t, C = 0;
    int* S;
    int* T;

    scanf("%d", &n);
    S = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    T = malloc(q * sizeof(int));
    for (i = 0; i < q; i++) {
        scanf("%d", &T[i]);
    }

    HashSet* set = createHashSet(n);
    for (i = 0; i < n; i++) {
        insert(set, S[i]);
    }

    for (i = 0; i < q; i++) {
        if (contains(set, T[i])) {
            C++;
        }
    }

    printf("%d\n", C);

    destroyHashSet(set);
    free(S);
    free(T);

    return 0;
}