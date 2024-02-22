#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char suit;
  int value;
} Card;

// Compare function for qsort
int cmp(const void *a, const void *b) {
  Card *cardA = (Card *)a;
  Card *cardB = (Card *)b;
  if (cardA->value != cardB->value)
    return cardA->value - cardB->value;
  return cardA->suit - cardB->suit;
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
    if(i != minj) {
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
    }
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
  // Using qsort instead of BubbleSort
  qsort(BC, N, sizeof(Card), cmp);
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