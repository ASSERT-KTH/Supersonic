#include <stdio.h>
typedef struct {
  char suit;
  int value;
} Card;
void BubbleSort(Card A[], int N) {
  int i, j;
  for (i = 0; i < N - 1; i++) {
    for (j = N - 1; j > i; j--) {
      if (A[j].value < A[j - 1].value) {
        Card temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;
      }
    }
  }
}
void SelectionSort(Card A[], int N) {
  int i, j;
  int minj;
  for (i = 0; i < N - 1; i++) {
    minj = i;
    for (j = i + 1; j < N; j++) {
      if (A[j].value < A[minj].value) {
        minj = j;
      }
    }
    Card temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
  }
}
int main() {
  int N;
  scanf("%d\n", &N);
  int i;
  Card BC[36];
  Card SC[36];
  for (i = 0; i < N; i++) {
    scanf("%c", &BC[i].suit);
    scanf("%d ", &BC[i].value);
    SC[i] = BC[i];
  }
  BubbleSort(BC, N);
  SelectionSort(SC, N);
  for (i = 0; i < N; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  puts("\nStable");
  for (i = 0; i < N; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  puts("\nStable");
  for (i = 0; i < N; i++) {
    if (BC[i].suit != SC[i].suit) {
      puts("Not stable");
      return 0;
    }
  }
  puts("Stable");
  return 0;
}