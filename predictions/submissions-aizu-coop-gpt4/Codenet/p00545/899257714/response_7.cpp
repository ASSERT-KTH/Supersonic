#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MIN = -(LONG_LONG_MAX - 1);

int main() {
  int N, Q;
  ll T;
  cin >> N >> T >> Q;
  vector<pair<ll, int>> people(N);
  for (int i = 0; i < N; i++) {
    cin >> people[i].first >> people[i].second;
  }
  sort(people.begin(), people.end());

  vector<ll> final_positions(N, MIN);
  ll east = MIN;
  ll t;
  for (int i = 0; i < N; i++) {
    if (people[i].second == 1) {
      east = people[i].first;
      if (i < N-1 && people[i+1].second == 2) {
        t = (east + people[i+1].first) / 2;
        final_positions[i] = min(east + T, t);
        final_positions[i+1] = min(people[i+1].first + T, t);
      } else {
        final_positions[i] = east + T;
      }
    }
  }
  ll west = MIN;
  for (int i = N-1; i >= 0; i--) {
    if (people[i].second == 2) {
      west = people[i].first;
      if (i > 0 && people[i-1].second == 1) {
        t = (west + people[i-1].first) / 2;
        final_positions[i] = max(west - T, t);
        final_positions[i-1] = max(people[i-1].first - T, t);
      } else {
        final_positions[i] = west - T;
      }
    }
  }

  for (int i = 0; i < Q; i++) {
    int query;
    cin >> query;
    query--;
    cout << final_positions[query] << endl;
  }

  return 0;
}