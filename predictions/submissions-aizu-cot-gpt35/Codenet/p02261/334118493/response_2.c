#include <stdio.h>

typedef struct {
  char suit;
  int value;
} Card;

void quickSort(Card A[], int low, int high) {
  if (low < high) {
    int pi = partition(A, low, high);
    quickSort(A, low, pi - 1);
    quickSort(A, pi + 1, high);
  }
}

int partition(Card A[], int low, int high) {
  Card pivot = A[high];
  int i = (low - 1);
  
  for (int j = low; j <= high - 1; j++) {
    if (A[j].value < pivot.value) {
      i++;
      swap_Card(&A[i], &A[j]);
    }
  }
  
  swap_Card(&A[i + 1], &A[high]);
  return (i + 1);
}

void swap_Card(Card *x, Card *y) {
  Card temp = *x;
  *x = *y;
  *y = temp;
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
  
  quickSort(BC, 0, N - 1);
  quickSort(SC, 0, N - 1);
  
  for (int i = 0; i < N - 1; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
  
  if (BC[0].suit != SC[0].suit) {
    puts("Not stable");
    return 0;
  }
  
  for (int i = 0; i < N - 1; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  printf("%c%d\n", SC[N - 1].suit, SC[N - 1].value);
  
  puts("Stable");
  
  return 0;
}