#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
  char suit;
  int value;
} Card;

void sortCards(Card A[], int N) {
  for (int i = 0; i < N - 1; i++) {
    for (int j = N - 1; j > i; j--) {
      if (A[j].value < A[j - 1].value) {
        swap(A[j], A[j - 1]);
      }
    }
  }
}

int main() {
  int N;
  cin >> N;

  Card BC[36];
  Card SC[36];

  for (int i = 0; i < N; i++) {
    cin >> BC[i].suit >> BC[i].value;
    SC[i] = BC[i];
  }

  sortCards(BC, N);
  sort(SC, SC + N, [](Card a, Card b) {
    return a.value < b.value;
  });

  for (int i = 0; i < N; i++) {
    cout << BC[i].suit << BC[i].value << " ";
  }
  cout << endl;

  if (equal(BC, BC + N, SC, [](Card a, Card b) {
    return a.suit == b.suit && a.value == b.value;
  })) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }

  for (int i = 0; i < N; i++) {
    cout << SC[i].suit << SC[i].value << " ";
  }
  cout << endl;

  return 0;
}