#include <stdio.h>
#include <algorithm>

struct Card {
  char suit;
  int value;
};

void BubbleSort(Card A[], int N) {
  bool flag = true;
  for (int i = 0; flag; i++) {
    flag = false;
    for (int j = N - 1; j >= i + 1; j--) {
      if (A[j].value < A[j - 1].value) {
        std::swap(A[j], A[j - 1]);
        flag = true;
      }
    }
  }
}

void SelectionSort(Card A[], int N) {
  for (int i = 0; i < N - 1; i++) {
    int minj = i;
    for (int j = i + 1; j < N; j++) {
      if (A[j].value < A[minj].value) {
        minj = j;
      }
    }
    if (i != minj) {
      std::swap(A[i], A[minj]);
    }
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
  std::string stability = (std::is_sorted(BC, BC + N, [](Card a, Card b){ return a.value < b.value; }) ? "Stable" : "Not stable");
  printf("%c%d", BC[0].suit, BC[0].value);
  for (int i = 1; i < N; i++) {
    printf(" %c%d", BC[i].suit, BC[i].value);
  }
  printf("\n%s\n", stability.c_str());
  printf("%c%d", SC[0].suit, SC[0].value);
  for (int i = 1; i < N; i++) {
    printf(" %c%d", SC[i].suit, SC[i].value);
  }
  printf("\n%s\n", (stability == "Stable" ? "Stable" : "Not stable"));
  return 0;
}