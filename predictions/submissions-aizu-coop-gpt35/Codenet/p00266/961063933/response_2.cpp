#include <iostream>
using namespace std;

const int MAX_N = 100000;
const int divisor = 1000000007;

long long factmodary[MAX_N + 1];
int word[MAX_N];
int bubblecount[MAX_N + 1];

int fenwick[MAX_N + 1];

int query(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += fenwick[idx];
    idx -= idx & -idx;
  }
  return sum;
}

void update(int idx, int val) {
  while (idx <= MAX_N) {
    fenwick[idx] += val;
    idx += idx & -idx;
  }
}

int main() {
  factmodary[0] = 1;
  for (int i = 1; i <= MAX_N; i++) {
    factmodary[i] = (factmodary[i - 1] * i) % divisor;
  }

  int N, R;
  while (cin >> N && N != 0) {
    cin >> R;

    for (int i = 0; i < N; i++) {
      word[i] = i + 1;
    }

    for (int i = 0; i < R; i++) {
      int s, t;
      cin >> s >> t;
      swap(word[s - 1], word[t - 1]);
    }

    for (int i = 0; i <= N; i++) {
      bubblecount[i] = 0;
    }

    for (int i = 0; i < N; i++) {
      bubblecount[word[i]] = i + 1;
      update(i + 1, 1);
    }

    long long ans = factmodary[N - 1] * (word[0] - 1);

    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum = query(word[i] - 1);

      update(bubblecount[word[i]], -1);

      facttime -= bubblenum;
      ans += factmodary[N - (i + 1)] * facttime;
      ans %= divisor;
    }

    cout << ans << "\n";
  }

  return 0;
}