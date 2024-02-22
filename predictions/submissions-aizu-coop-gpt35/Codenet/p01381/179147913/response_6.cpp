#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k) {
    if (n / 2 < k) {
      printf("-1\n");
      continue;
    }

    // Step 1: Allocate memory for p outside the loop
    vector<int> p(n + 2);
    p[0] = 0;

    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }

    // Step 2: Precalculate modulo values to reduce modulo operations
    vector<int> p_mod(n + 2);
    for (int i = 0; i < n + 2; i++) {
      p_mod[i] = p[i] % n;
    }

    // Step 3: Store the generated pairs in memory and print them outside the nested loops
    vector<pair<int, int>> pairs;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n - 1; j++) {
        int a = (p_mod[j] + i) % n + 1;
        int b = (p_mod[j + 1] + i) % n + 1;
        pairs.emplace_back(a, b);
      }
    }

    // Print the generated pairs
    for (const auto& pair : pairs) {
      printf("%d %d\n", pair.first, pair.second);
    }
  }

  return 0;
}