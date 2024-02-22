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

void printArray(Card A[], int N) {
  int i;
  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", A[i].suit, A[i].value);
  }
  printf("%c%d\n", A[N - 1].suit, A[N - 1].value);
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
  printArray(BC, N);
  puts("Stable");
  printArray(SC, N);
  for (i = 0; i < N; i++) {
    if (BC[i].suit != SC[i].suit) {
      puts("Not stable");
      return 0;
    }
  }
  puts("Stable");
  return 0;
}