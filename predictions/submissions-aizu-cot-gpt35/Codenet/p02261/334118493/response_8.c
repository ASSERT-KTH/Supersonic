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

void sortCards(Card A[], int N) {
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
    
    if (minj != i) {
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
    }
  }
}

int main() {
  int N;
  scanf("%d\n", &N);
  
  int i;
  Card BC[36];
  Card SC[36];
  
  for (i = 0; i < N; i++) {
    Card c;
    scanf("%c", &c.suit);
    scanf("%d ", &c.value);
    BC[i] = c;
    SC[i] = c;
  }
  
  sortCards(BC, N);
  sortCards(SC, N);
  
  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
  
  if (memcmp(BC, SC, sizeof(Card) * N) == 0) {
    puts("Stable");
  } else {
    puts("Not stable");
  }
  
  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  printf("%c%d\n", SC[N - 1].suit, SC[N - 1].value);
  
  return 0;
}