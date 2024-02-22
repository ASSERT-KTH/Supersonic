#include <stdio.h>

typedef struct {
  char suit;
  int value;
} Card;

void swap_Card(Card* x, Card* y) {
  Card temp = *x;
  *x = *y;
  *y = temp;
}

void StableSort(Card A[], int N) {
  int i, j;
  int minj;
  Card temp;
  int isSorted = 1; // Flag to check if any swaps were made

  for (i = 0; i < N - 1; i++) {
    minj = i;
    isSorted = 1;

    for (j = i + 1; j < N; j++) {
      if (A[j].value < A[minj].value) {
        minj = j;
        isSorted = 0; // Minimum element has changed, array is not sorted
      }
    }

    if (isSorted) {
      break; // Array is already sorted, terminate the loop
    }

    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
  }
}

int main() {
  int N;
  scanf("%d\n", &N);
  int i;
  Card BC[36];

  for (i = 0; i < N; i++) {
    Card c;
    scanf("%c", &c.suit);
    scanf("%d ", &c.value);
    BC[i] = c;
  }

  StableSort(BC, N);

  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }

  printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
  puts("Stable");

  for (i = 0; i < N; i++) {
    if (BC[i].value == BC[i + 1].value) {
      puts("Not stable");
      return 0;
    }
  }

  puts("Stable");
  return 0;
}