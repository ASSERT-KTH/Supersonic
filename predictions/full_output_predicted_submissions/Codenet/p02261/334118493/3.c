#include <stdio.h>
#include <stdlib.h>
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
  for (i = 0; i < N - 1; i++) {
    for (j = N - 1; j > i; j--) {
      if (A[j].value < A[j - 1].value) {
        temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;
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
    SC[i] = c