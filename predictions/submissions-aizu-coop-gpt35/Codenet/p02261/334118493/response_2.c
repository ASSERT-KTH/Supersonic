#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char suit;
  int value;
} Card;

void QuickSort(Card A[], int low, int high) {
  if (low < high) {
    int pivot = Partition(A, low, high);
    QuickSort(A, low, pivot - 1);
    QuickSort(A, pivot + 1, high);
  }
}

int Partition(Card A[], int low, int high) {
  Card pivot = A[high];
  int i = low - 1;
  
  for (int j = low; j < high; j++) {
    if (A[j].value <= pivot.value) {
      i++;
      swap_Card(&A[i], &A[j]);
    }
  }
  
  swap_Card(&A[i + 1], &A[high]);
  
  return i + 1;
}

void Heapify(Card A[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  
  if (left < n && A[left].value > A[largest].value) {
    largest = left;
  }
  
  if (right < n && A[right].value > A[largest].value) {
    largest = right;
  }
  
  if (largest != i) {
    swap_Card(&A[i], &A[largest]);
    Heapify(A, n, largest);
  }
}

void HeapSort(Card A[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    Heapify(A, n, i);
  }
  
  for (int i = n - 1; i > 0; i--) {
    swap_Card(&A[0], &A[i]);
    Heapify(A, i, 0);
  }
}

int main() {
  int N;
  scanf("%d\n", &N);
  
  Card* BC = (Card*)malloc(N * sizeof(Card));
  Card* SC = (Card*)malloc(N * sizeof(Card));
  
  for (int i = 0; i < N; i++) {
    char cardString[10];
    scanf("%s", cardString);
    sscanf(cardString, "%c%d", &BC[i].suit, &BC[i].value);
    SC[i] = BC[i];
  }
  
  QuickSort(BC, 0, N - 1);
  HeapSort(SC, N);
  
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
  
  free(BC);
  free(SC);
  
  return 0;
}