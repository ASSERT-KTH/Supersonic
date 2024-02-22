#include <stdio.h>
typedef struct {
  char suit;
  int value;
} Card;

void SelectionSort(Card A[], int N) {
  int i, j, minj;
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

void printCards(Card A[], int N){
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
  Card Cards[36];
  for (i = 0; i < N; i++) {
    scanf("%c%d ", &Cards[i].suit, &Cards[i].value);
  }
  SelectionSort(Cards, N);
  printCards(Cards, N);
  puts("Stable");
  return 0;
}