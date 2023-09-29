#include <stdio.h>
#include <algorithm>

typedef struct {
  char suit;
  int value;
} Card;

int compare(const void* a, const void* b) {
  return (((Card*)a)->value - ((Card*)b)->value);
}

int main() {
  int N;
  scanf("%d\n", &N);
  Card BC[36];
  Card SC[36];
  for (int i = 0; i < N; i++) {
    Card c;
    scanf("%c", &c.suit);
    scanf("%d ", &c.value);
    BC[i] = c;
    SC[i] = c;
  }
  std::qsort(BC, N, sizeof(Card), compare);
  std::stable_sort(SC, SC + N, [](Card a, Card b) { return a.value < b.value; });
  for (int i = 0; i < N; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
    if (BC[i].suit != SC[i].suit) {
      puts("Not stable");
      return 0;
    }
  }
  puts("Stable");
  return 0;
}