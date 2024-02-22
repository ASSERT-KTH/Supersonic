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
        A[j].value ^= A[j-1].value;
        A[j-1].value ^= A[j].value;
        A[j].value ^= A[j-1].value;
        char temp_suit = A[j].suit;
        A[j].suit = A[j - 1].suit;
        A[j - 1].suit = temp_suit;
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
    if (minj != i) {
      A[i].value ^= A[minj].value;
      A[minj].value ^= A[i].value;
      A[i].value ^= A[minj].value;
      char temp_suit = A[i].suit;
      A[i].suit = A[minj].suit;
      A[minj].suit = temp_suit;
    }
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
    scanf("%c%d ", &c.suit, &c.value);
    BC[i] = c;
    SC[i] = c;
  }
  BubbleSort(BC, N);
  SelectionSort(SC, N);
  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
  puts("Stable");
  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  printf("%c%d\n", SC[N - 1].suit, SC[N - 1].value);
  for (i = 0; i < N; i++) {
    if (BC[i].suit != SC[i].suit) {
      puts("Not stable");
      return 0;
    }
  }
  puts("Stable");
  return 0;
}