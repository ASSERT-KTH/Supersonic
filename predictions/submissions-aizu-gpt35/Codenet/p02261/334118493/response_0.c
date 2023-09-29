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
bool cmp(Card a, Card b){
    return a.value < b.value;
}
void BubbleSort(Card A[], int N) {
  int i, j;
  Card temp;
  for (i = 0; i < N - 1; i++) {
    for (j = N - 1; j > i; j--) {
      if (A[j].value < A[j - 1].value) {
        temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;
      }
    }
  }
}
void SelectionSort(Card A[], int N) {
  int i, j;
  int minj;
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
int main() {
  int N;
  scanf("%d\n", &N);
  int i, j;
  Card BC[36];
  Card SC[36];
  for (i = 0; i < N; i++) {
    Card c;
    scanf("%c", &c.suit);
    scanf("%d ", &c.value);
    BC[i] = c;
    SC[i] = c;
  }
  BubbleSort(BC, N);
  SelectionSort(SC, N);
  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
  if(std::is_sorted(SC,SC+N,cmp)){
      puts("Stable");
  }
  else{
      puts("Not stable");
  }
  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  printf("%c%d\n", SC[N - 1].suit, SC[N - 1].value);
  if(std::is_sorted(SC,SC+N,cmp)){
      puts("Stable");
  }
  else{
      puts("Not stable");
  }
  return 0;
}