#include <stdio.h>
#include <algorithm>

typedef struct {
  char suit;
  int value;
} Card;

bool compareCard(Card a, Card b) {
  return a.value < b.value;
}

int main() {
  int N;
  scanf("%d\n", &N);
  Card BC[36];
  Card SC[36];
  
  for (int i = 0; i < N; i++) {
    scanf("%c", &BC[i].suit);
    scanf("%d ", &BC[i].value);
    SC[i] = BC[i];
  }
  
  std::stable_sort(BC, BC+N, compareCard);
  std::stable_sort(SC, SC+N, compareCard);
  
  for (int i = 0; i < N; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  puts("\nStable");
  
  for (int i = 0; i < N; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  puts("\nStable");
  
  for (int i = 0; i < N; i++) {
    if (BC[i].suit != SC[i].suit) {
      puts("Not stable");
      return 0;
    }
  }
  
  puts("Stable");
  return 0;
}