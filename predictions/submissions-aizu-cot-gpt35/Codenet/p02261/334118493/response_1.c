#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char suit;
  int value;
} Card;

void quickSort(Card A[], int low, int high) {
  if (low < high) {
    int pivot = partition(A, low, high);
    quickSort(A, low, pivot - 1);
    quickSort(A, pivot + 1, high);
  }
}

int partition(Card A[], int low, int high) {
  Card pivot = A[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (A[j].value <= pivot.value) {
      i++;
      swapCard(&A[i], &A[j]);
    }
  }
  swapCard(&A[i + 1], &A[high]);
  return i + 1;
}

void swapCard(Card* x, Card* y) {
  Card temp = *x;
  *x = *y;
  *y = temp;
}

void selectionSort(Card A[], int N) {
  for (int i = 0; i < N - 1; i++) {
    int minj = i;
    for (int j = i + 1; j < N; j++) {
      if (A[j].value < A[minj].value) {
        minj = j;
      }
    }
    swapCard(&A[i], &A[minj]);
  }
}

int main() {
  int N;
  scanf("%d\n", &N);

  Card* BC = (Card*)malloc(N * sizeof(Card));
  Card* SC = (Card*)malloc(N * sizeof(Card));

  char line[100];
  fgets(line, sizeof(line), stdin);
  char* token = strtok(line, " ");
  for (int i = 0; i < N; i++) {
    BC[i].suit = token[0];
    BC[i].value = atoi(token + 1);
    SC[i] = BC[i];
    token = strtok(NULL, " ");
  }

  quickSort(BC, 0, N - 1);
  selectionSort(SC, N);

  for (int i = 0; i < N - 1; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
  puts("Stable");

  for (int i = 0; i < N - 1; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  printf("%c%d\n", SC[N - 1].suit, SC[N - 1].value);

  int stable = 1;
  for (int i = 0; i < N; i++) {
    if (BC[i].suit != SC[i].suit) {
      stable = 0;
      break;
    }
  }
  if (stable) {
    puts("Stable");
  } else {
    puts("Not stable");
  }

  free(BC);
  free(SC);

  return 0;
}