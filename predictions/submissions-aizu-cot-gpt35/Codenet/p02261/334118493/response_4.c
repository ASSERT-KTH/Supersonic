#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
  char suit;
  int value;
} Card;

void stableSort(vector<Card>& cards) {
  int n = cards.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j > i; j--) {
      if (cards[j].value < cards[j - 1].value) {
        swap(cards[j], cards[j - 1]);
      }
    }
  }
}

int main() {
  int N;
  cin >> N;
  vector<Card> cards(N);
  for (int i = 0; i < N; i++) {
    cin >> cards[i].suit >> cards[i].value;
  }
  
  vector<Card> sortedCards = cards;
  stableSort(sortedCards);
  sort(cards.begin(), cards.end(), [](const Card &a, const Card &b) {
    return a.value < b.value;
  });

  bool stable = true;
  for (int i = 0; i < N; i++) {
    if (cards[i].suit != sortedCards[i].suit) {
      stable = false;
      break;
    }
  }

  for (int i = 0; i < N - 1; i++) {
    cout << sortedCards[i].suit << sortedCards[i].value << " ";
  }
  cout << sortedCards[N - 1].suit << sortedCards[N - 1].value << endl;
  cout << (stable ? "Stable" : "Not stable") << endl;

  for (int i = 0; i < N - 1; i++) {
    cout << cards[i].suit << cards[i].value << " ";
  }
  cout << cards[N - 1].suit << cards[N - 1].value << endl;
  cout << "Stable" << endl;

  return 0;
}