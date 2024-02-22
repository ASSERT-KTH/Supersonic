#include <stdio.h>

typedef struct {
  char suit;
  int value;
} Card;

void swap_Card(Card *x, Card *y) {
  Card temp = *x;
  *x = *y;
  *y = temp;
}

void sortCards(Card A[], int N) {
  int i, j;
  int minj;
  for (i = 0; i < N - 1; i++) {
    minj = i;
    for (j = i + 1; j < N; j++) {
      if (A[j].value < A[minj].value) {
        minj = j;
      }
    }
    swap_Card(&A[i], &A[minj]);
  }
}

int main() {
  int N;
  scanf("%d\n", &N);

  Card BC[36];
  Card SC[36];

  for (int i = 0; i < N; i++) {
    scanf("%c%d ", &BC[i].suit, &BC[i].value);
    SC[i] = BC[i];
  }

  sortCards(BC, N);

  for (int i = 0; i < N; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  puts("Stable");

  sortCards(SC, N);

  for (int i = 0; i < N; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  puts("Stable");

  for (int i = 0; i < N; i++) {
    if (BC[i].suit != SC[i].suit) {
      puts("Not stable");
      return 0;
    }
  }

  puts("Stable");
  return 0;
}