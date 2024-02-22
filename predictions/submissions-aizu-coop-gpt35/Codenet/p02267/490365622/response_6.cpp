#include <stdio.h>
#include <stdbool.h>

// A simple hash set implementation
typedef struct HashSet {
  int capacity;
  int size;
  int* data;
} HashSet;

// Initialize a hash set with a given capacity
void initHashSet(HashSet* set, int capacity) {
  set->capacity = capacity;
  set->size = 0;
  set->data = (int*)malloc(sizeof(int) * capacity);
}

// Insert an element into the hash set
void insertHashSet(HashSet* set, int element) {
  if (set->size == set->capacity) {
    // Handle resizing if needed
    int newCapacity = set->capacity * 2;
    int* newData = (int*)malloc(sizeof(int) * newCapacity);
    memcpy(newData, set->data, sizeof(int) * set->capacity);
    free(set->data);
    set->data = newData;
    set->capacity = newCapacity;
  }
  set->data[set->size++] = element;
}

// Check if an element exists in the hash set
bool containsHashSet(HashSet* set, int element) {
  for (int i = 0; i < set->size; i++) {
    if (set->data[i] == element) {
      return true;
    }
  }
  return false;
}

int main() {
  int n, q, i, cnt = 0;
  scanf("%d", &n);

  // Create a hash set to store the elements of S
  HashSet setS;
  initHashSet(&setS, n);
  for (i = 0; i < n; i++) {
    int s;
    scanf("%d", &s);
    insertHashSet(&setS, s);
  }

  scanf("%d", &q);

  // Count the number of elements in T that are present in S
  for (i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (containsHashSet(&setS, t)) {
      cnt++;
    }
  }

  printf("%d\n", cnt);

  return 0;
}