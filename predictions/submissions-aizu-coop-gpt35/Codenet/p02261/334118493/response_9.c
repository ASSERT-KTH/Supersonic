#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char suit;
  int value;
} Card;

void merge(Card A[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;
  
  Card *L = (Card*)malloc(n1 * sizeof(Card));
  Card *R = (Card*)malloc(n2 * sizeof(Card));

  for (i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }

  for (j = 0; j < n2; j++) {
    R[j] = A[mid + 1 + j];
  }

  i = 0;
  j = 0;
  k = left;

  while (i < n1 && j < n2) {
    if (L[i].value <= R[j].value) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    A[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    A[k] = R[j];
    j++;
    k++;
  }

  free(L);
  free(R);
}

void mergeSort(Card A[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int N;
  scanf("%d\n", &N);

  Card* BC = (Card*)malloc(N * sizeof(Card));

  for (int i = 0; i < N; i++) {
    Card c;
    scanf("%c%d ", &c.suit, &c.value);
    BC[i] = c;
  }

  mergeSort(BC, 0, N - 1);

  for (int i = 0; i < N - 1; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
  puts("Stable");

  free(BC);

  return 0;
}