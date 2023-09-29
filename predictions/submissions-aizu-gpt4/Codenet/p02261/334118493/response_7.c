#include <stdio.h>
typedef struct {
  char suit;
  int value;
} Card;

void swap_Card(Card *x, Card *y) {
  if (x != y) {
    Card temp = *x;
    *x = *y;
    *y = temp;
  }
}

void BubbleSort(Card A[], int N) {
  int i, j;
  for (i = 0; i < N - 1; i++) {
    for (j = N - 1; j > i; j--) {
      if (A[j].value < A[j - 1].value) {
        swap_Card(&A[j], &A[j - 1]);
      }
    }
  }
}

void SelectionSort(Card A[], int N) {
  int i, j, minj;
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
  int N, i;
  scanf("%d\n", &N);
  Card BC[36], SC[36], c;
  for (i = 0; i < N; i++) {
    scanf("%c", &c.suit);
    scanf("%d ", &c.value);
    BC[i] = SC[i] = c;
  }
  BubbleSort(BC, N);
  SelectionSort(SC, N);
  for (i = 0; i < N; i++) {
    printf("%c%d%c", BC[i].suit, BC[i].value, i < N - 1 ? ' ' : '\n');
  }
  puts("Stable");
  for (i = 0; i < N; i++) {
    printf("%c%d%c", SC[i].suit, SC[i].value, i < N - 1 ? ' ' : '\n');
    if (BC[i].suit != SC[i].suit) {
      puts("\nNot stable");
      return 0;
    }
  }
  puts("Stable");
  return 0;
}