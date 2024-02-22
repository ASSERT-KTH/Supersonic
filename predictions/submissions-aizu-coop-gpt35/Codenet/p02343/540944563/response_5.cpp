#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

int N;

vector<pair<int, int>> disjointSets;

int getBoss(int id) {
  int* ptr = &disjointSets[id].first;
  while (*ptr != id) {
    disjointSets[id].first = disjointSets[*ptr].first;
    id = *ptr;
    ptr = &disjointSets[id].first;
  }
  return id;
}

bool isSame(int x, int y) { return getBoss(x) == getBoss(y); }

void unite(int x, int y) {
  int bossX = getBoss(x);
  int bossY = getBoss(y);
  if (bossX == bossY)
    return;
  if (disjointSets[bossX].second > disjointSets[bossY].second) {
    disjointSets[bossY].first = bossX;
  } else if (disjointSets[bossX].second < disjointSets[bossY].second) {
    disjointSets[bossX].first = bossY;
  } else {
    disjointSets[bossY].first = bossX;
    disjointSets[bossX].second++;
  }
}

int main() {
  int Q, command, x, y;
  cin >> N >> Q;

  disjointSets.reserve(N);
  for (int i = 0; i < N; i++) {
    disjointSets.emplace_back(i, 1);
  }

  for (int i = 0; i < Q; i++) {
    cin >> command >> x >> y;
    if (command == 0) {
      unite(x, y);
    } else {
      cout << isSame(x, y) << endl;
    }
  }

  return 0;
}