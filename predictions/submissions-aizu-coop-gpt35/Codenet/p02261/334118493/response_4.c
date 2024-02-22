#include <stdio.h>

typedef struct {
  char suit;
  int value;
} Card;

void swap_Card(Card* x, Card* y) {
  Card temp = *x;
  *x = *y;
  *y = temp;
}

void QuickSort(Card A[], int low, int high) {
  if (low < high) {
    int pivot = partition(A, low, high);
    QuickSort(A, low, pivot - 1);
    QuickSort(A, pivot + 1, high);
  }
}

int partition(Card A[], int low, int high) {
  Card pivot = A[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (A[j].value < pivot.value) {
      i++;
      swap_Card(&A[i], &A[j]);
    }
  }
  swap_Card(&A[i + 1], &A[high]);
  return i + 1;
}

int main() {
  int N;
  scanf("%d\n", &N);

  Card BC[36];
  Card SC[36];

  for (int i = 0; i < N; i++) {
    Card c;
    scanf("%c%d ", &c.suit, &c.value);
    BC[i] = c;
  }

  // Copy BC array to SC array
  for (int i = 0; i < N; i++) {
    SC[i] = BC[i];
  }

  QuickSort(BC, 0, N - 1);
  QuickSort(SC, 0, N - 1);

  for (int i = 0; i < N - 1; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
  puts("Stable");

  for (int i = 0; i < N - 1; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  printf("%c%d\n", SC[N - 1].suit, SC[N - 1].value);

  for (int i = 0; i < N; i++) {
    if (BC[i].suit != SC[i].suit) {
      puts("Not stable");
      return 0;
    }
  }

  puts("Stable");
  return 0;
}