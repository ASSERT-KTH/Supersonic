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

void QuickSort(Card A[], int low, int high) {
  if (low < high) {
    int pivot = A[low].value;
    int i = low + 1;
    int j = high;
    while (i <= j) {
      if (A[i].value <= pivot) {
        i++;
      } else if (A[j].value > pivot) {
        j--;
      } else {
        swap_Card(&A[i], &A[j]);
        i++;
        j--;
      }
    }
    swap_Card(&A[low], &A[j]);
    QuickSort(A, low, j - 1);
    QuickSort(A, j + 1, high);
  }
}

int main() {
  int N;
  scanf("%d\n", &N);

  Card BC[36];
  Card SC[36];

  for (int i = 0; i < N; i++) {
    Card c;
    scanf("%c", &c.suit);
    scanf("%d ", &c.value);
    BC[i] = c;
    SC[i] = c;
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