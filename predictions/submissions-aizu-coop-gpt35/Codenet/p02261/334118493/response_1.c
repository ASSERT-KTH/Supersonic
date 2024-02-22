#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char suit;
  int value;
} Card;

void swap_Card(Card *x, Card *y) {
  if (x != y) {
    x->value ^= y->value;
    y->value ^= x->value;
    x->value ^= y->value;
  }
}

int compareCard(const void *a, const void *b) {
  Card *cardA = (Card *)a;
  Card *cardB = (Card *)b;
  return cardA->value - cardB->value;
}

int main() {
  int N;
  scanf("%d\n", &N);
  int i;
  Card cards[36];
  for (i = 0; i < N; i++) {
    Card c;
    scanf("%c", &c.suit);
    scanf("%d ", &c.value);
    cards[i] = c;
  }
  
  qsort(cards, N, sizeof(Card), compareCard);
  
  for (i = 0; i < N - 1; i++) {
    printf("%c%d ", cards[i].suit, cards[i].value);
  }
  printf("%c%d\n", cards[N - 1].suit, cards[N - 1].value);
  
  for (i = 1; i < N; i++) {
    if (cards[i].value == cards[i - 1].value) {
      puts("Not stable");
      return 0;
    }
  }
  
  puts("Stable");
  return 0;
}