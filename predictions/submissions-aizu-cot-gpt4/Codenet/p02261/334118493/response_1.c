#include <stdio.h>
typedef struct {
  char suit;
  int value;
} Card;

void BubbleSort(Card* A[], int N) {
  int i, j;
  Card* temp;
  for (i = 0; i < N - 1; i++) {
    for (j = N - 1; j > i; j--) {
      if (A[j]->value < A[j - 1]->value) {
        temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;
      }
    }
  }
}

void SelectionSort(Card* A[], int N) {
  int i, j;
  int minj;
  Card* temp;
  for (i = 0; i < N - 1; i++) {
    minj = i;
    for (j = i + 1; j < N; j++) {
      if (A[j]->value < A[minj]->value) {
        minj = j;
      }
    }
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
  }
}

void printCards(Card* A[], int N) {
  int i;
  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", A[i]->suit, A[i]->value);
  }
  printf("%c%d\n", A[N - 1]->suit, A[N - 1]->value);
}

int main() {
  int N;
  scanf("%d\n", &N);
  int i;
  Card BC[36], SC[36];
  Card* pBC[36], * pSC[36];
  for (i = 0; i < N; i++) {
    scanf("%c", &BC[i].suit);
    scanf("%d ", &BC[i].value);
    SC[i] = BC[i];
    pBC[i] = &BC[i];
    pSC[i] = &SC[i];
  }
  BubbleSort(pBC, N);
  SelectionSort(pSC, N);
  printCards(pBC, N);
  puts("Stable");
  printCards(pSC, N);
  for (i = 0; i < N; i++) {
    if (pBC[i]->suit != pSC[i]->suit) {
      puts("Not stable");
      return 0;
    }
  }
  puts("Stable");
  return 0;
}