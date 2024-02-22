#include <stdio.h>

// Include the necessary header for the hash set data structure
#include <stdbool.h>
#include <stdlib.h>

// Define a hash set structure to store the elements of array S
typedef struct {
    int key;
    bool present;
} HashSet;

// Create a hash set with a specified size
HashSet* createHashSet(int size) {
    HashSet* set = (HashSet*)malloc(size * sizeof(HashSet));
    for (int i = 0; i < size; i++) {
        set[i].present = false;
    }
    return set;
}

// Insert an element into the hash set
void insertIntoHashSet(HashSet* set, int key) {
    set[key].present = true;
}

// Check if an element exists in the hash set
bool isInHashSet(HashSet* set, int key) {
    return set[key].present;
}

int main() {
    int n, q, i, cnt = 0;
    scanf("%d", &n);

    // Allocate memory for the hash set
    HashSet* set = createHashSet(10000);

    // Read the elements of array S and insert them into the hash set
    for (i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        insertIntoHashSet(set, element);
    }

    scanf("%d", &q);

    // Read the elements of array T and check for matches in the hash set
    for (i = 0; i < q; i++) {
        int element;
        scanf("%d", &element);
        if (isInHashSet(set, element)) {
            cnt++;
        }
    }

    printf("%d\n", cnt);

    // Free the memory allocated for the hash set
    free(set);

    return 0;
}