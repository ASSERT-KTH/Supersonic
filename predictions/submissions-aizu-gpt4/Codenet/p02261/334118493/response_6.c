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
  int N;
  scanf("%d\n", &N);
  int i;
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
  for (i = 0; i < N; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
    if (BC[i].suit != SC[i].suit) {
      puts("\nNot stable");
      return 0;
    }
  }
  puts("\nStable");
  return 0;
}