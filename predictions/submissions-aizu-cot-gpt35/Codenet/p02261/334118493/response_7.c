#include <stdio.h>

typedef struct {
  char suit;
  int value;
} Card;

void sort_Cards(Card A[], int N) {
  int i, j;
  int sorted;
  Card temp;

  for (i = 0; i < N - 1; i++) {
    sorted = 1;
    for (j = N - 1; j > i; j--) {
      if (A[j].value < A[j - 1].value) {
        temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;
        sorted = 0;
      }
    }
    if (sorted) {
      break;
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

  sort_Cards(BC, N);
  sort_Cards(SC, N);

  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
  puts("Stable");

  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  printf("%c%d\n", SC[N - 1].suit, SC[N - 1].value);

  for (i = 0; i < N; i++) {
    if (BC[i].suit != SC[i].suit) {
      puts("Not stable");
      return 0;
    }
  }

  puts("Stable");
  return 0;
}