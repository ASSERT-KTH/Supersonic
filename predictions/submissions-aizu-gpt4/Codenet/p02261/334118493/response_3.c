#include <stdio.h>
#include <algorithm>

typedef struct {
  char suit;
  int value;
} Card;

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
  
  std::stable_sort(BC, BC + N, [](const Card &a, const Card &b) { return a.value < b.value; });
  std::stable_sort(SC, SC + N, [](const Card &a, const Card &b) { return a.value < b.value; });
  
  for (int i = 0; i < N - 1; i++) {
    printf("%c%d ", BC[i].suit, BC[i].value);
  }
  printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
  puts("Stable");
  
  for (int i = 0; i < N - 1; i++) {
    printf("%c%d ", SC[i].suit, SC[i].value);
  }
  printf("%c%d\n", SC[N - 1].suit, SC[N - 1].value);

  if(std::equal(BC, BC + N, SC, [](const Card &a, const Card &b) { return a.suit == b.suit; }))
    puts("Stable");
  else
    puts("Not stable");
  
  return 0;
}