#include <stdio.h>
#include <algorithm>
typedef struct {
  char suit;
  int value;
} Card;
void swap_Card(Card *x, Card *y) {
  Card temp = *x;
  *x = *y;
  *y = temp;
}
void BubbleSort(Card A[], int N) {
  int i, j;
  bool flag = true;
  for (i = 0; flag; i++) {
    flag = false;
    for (j = N - 1; j >= i + 1; j--) {
      if (A[j].value < A[j - 1].value) {
        std::swap(A[j], A[j - 1]);
        flag = true;
      }
    }
  }
}
void SelectionSort(Card A[], int N) {
  int i, j;
  for (i = 0; i < N; i++) {
    int minj = i;
    for (j = i; j < N; j++) {
      if (A[j].value < A[minj].value) {
        minj = j;
      }
    }
    if (i != minj) std::swap(A[i], A[minj]);
  }
}
int main() {
  int N;
  scanf("%d\n", &N);
  Card BC[36];
  Card SC[36];
  for (int i = 0; i < N; i++) {
    scanf("%c%d ", &BC[i].suit, &BC[i].value);
    SC[i] = BC[i];
  }
  BubbleSort(BC, N);
  SelectionSort(SC, N);
  for (int i = 0; i < N; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  puts("");
  std::stable_sort(SC, SC + N, [](const Card& a, const Card& b) {
    return a.value < b.value;
  });
  for (int i = 0; i < N; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  puts("");
  bool flag = true;
  for (int i = 0; i < N; i++) {
    if (BC[i].suit != SC[i].suit) {
      flag = false;
      break;
    }
  }
  puts(flag ? "Stable" : "Not stable");
  return 0;
}