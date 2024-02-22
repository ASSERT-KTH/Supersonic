#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
  int data[MAX_SIZE];
  int size;
} Set;

void initSet(Set *set) {
  set->size = 0;
}

void addToSet(Set *set, int element) {
  set->data[set->size++] = element;
}

bool isInSet(Set *set, int element) {
  for (int i = 0; i < set->size; i++) {
    if (set->data[i] == element) {
      return true;
    }
  }
  return false;
}

int main() {
  int i, n, q, t, C = 0;
  Set S, T;

  initSet(&S);
  initSet(&T);

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &t);
    addToSet(&S, t);
  }

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &t);
    addToSet(&T, t);
  }

  for (i = 0; i < T.size; i++) {
    if (isInSet(&S, T.data[i])) {
      C++;
    }
  }

  printf("%d\n", C);
  return 0;
}