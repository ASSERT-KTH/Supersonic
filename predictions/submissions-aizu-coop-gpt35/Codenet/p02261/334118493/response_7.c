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

int partition(Card A[], int low, int high) {
  int pivot = A[high].value;
  int i = low - 1;
  
  for (int j = low; j <= high - 1; j++) {
    if (A[j].value < pivot) {
      i++;
      swap_Card(&A[i], &A[j]);
    }
  }
  
  swap_Card(&A[i + 1], &A[high]);
  return (i + 1);
}

void QuickSort(Card A[], int low, int high) {
  if (low < high) {
    int pi = partition(A, low, high);
    QuickSort(A, low, pi - 1);
    QuickSort(A, pi + 1, high);
  }
}

int main() {
  int N;
  scanf("%d\n", &N);
  
  Card cards[N];
  for (int i = 0; i < N; i++) {
    scanf("%c%d ", &cards[i].suit, &cards[i].value);
  }
  
  QuickSort(cards, 0, N - 1);
  
  int stable = 1;
  for (int i = 0; i < N - 1; i++) {
    printf("%c%d ", cards[i].suit, cards[i].value);
    if (cards[i].value == cards[i + 1].value && cards[i].suit > cards[i + 1].suit) {
      stable = 0;
    }
  }
  printf("%c%d\n", cards[N - 1].suit, cards[N - 1].value);
  
  if (stable) {
    puts("Stable");
  } else {
    puts("Not stable");
  }
  
  return 0;
}