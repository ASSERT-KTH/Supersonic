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

void BubbleSort(Card A[], int N) {
  int i, j;
  Card temp;
  bool swapped = true;
  for (i = 0; i < N - 1 && swapped; i++) {
    swapped = false;
    for (j = N - 1; j > i; j--) {
      if (A[j].value < A[j - 1].value) {
        temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;
        swapped = true;
      }
    }
  }
}

void SelectionSort(Card A[], int N) {
  int i, j;
  int minj;
  Card temp;
  for (i = 0; i < N - 1; i++) {
    minj = i;
    for (j = i + 1; j < N; j++) {
      if (A[j].value < A[minj].value) {
        minj = j;
      }
    }
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
  }
}

int main() {
  int N;
  scanf("%d\n", &N);
  int i, j;
  Card BC[36];
  Card SC[36];
  for (i = 0; i < N; i++) {
    Card c;
    scanf("%c", &c.suit);
    scanf("%d ", &c.value);
    BC[i] = c;
    SC[i] = c;
  }
  BubbleSort(BC, N);
  SelectionSort(SC, N);
  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
  if (N == 1) {
    puts("Stable");
    printf("%c%d\n", SC[0].suit, SC[0].value);
    return 0;
  }
  bool stable = true;
  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
    if (SC[i].value == SC[i+1].value) {
      for (j = 0; j < N; j++) {
        if (BC[j].value == SC[i].value && BC[j].suit != SC[i].suit) {
          stable = false;
          break;
        }
      }
    }
  }
  printf("%c%d\n", SC[N - 1].suit, SC[N - 1].value);
  if (SC[N-2].value == SC[N-1].value) {
    for (j = 0; j < N; j++) {
      if (BC[j].value == SC[N-1].value && BC[j].suit != SC[N-1].suit) {
        stable = false;
        break;
      }
    }
  }
  if (stable) {
    puts("Stable");
  } else {
    puts("Not stable");
  }
  return 0;
}