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

void SortCards(Card A[], int N, int sortType) {
  int i, j;
  int minj;
  Card temp;
  for (i = 0; i < N - 1; i++) {
    if (sortType == 0) {
      for (j = N - 1; j > i; j--) {
        if (A[j].value < A[j - 1].value) {
          swap_Card(&A[j], &A[j - 1]);
        }
      }
    } else {
      minj = i;
      for (j = i + 1; j < N; j++) {
        if (A[j].value < A[minj].value) {
          minj = j;
        }
      }
      swap_Card(&A[i], &A[minj]);
    }
  }
}

int main() {
  int N;
  scanf("%d\n", &N);

  Card BC[36];
  Card *SC = BC;

  for (int i = 0; i < N; i++) {
    scanf("%c%d ", &BC[i].suit, &BC[i].value);
  }

  SortCards(BC, N, 0);
  SortCards(SC, N, 1);

  for (int i = 0; i < N; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  printf("\nStable\n");

  for (int i = 0; i < N; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  printf("\n");

  for (int i = 0; i < N; i++) {
    if (BC[i].suit != SC[i].suit) {
      printf("Not stable\n");
      return 0;
    }
  }
  printf("Stable\n");
  return 0;
}