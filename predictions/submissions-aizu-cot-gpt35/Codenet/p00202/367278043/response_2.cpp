#include <bitset>
#include <cstdio>

const int MAX_N = 30;
const int MAX_X = 1000000;

int n, x, a[MAX_N];
std::bitset<MAX_X + 1> prime;
bool dp[MAX_X + 1];

int main() {
  prime[0] = true;
  prime[2] = true;
  for (int i = 3; i * i <= MAX_X; i += 2)
    prime[i] = true;
  for (int i = 3; i * i <= MAX_X; i += 2) {
    if (!prime[i])
      continue;
    for (int j = i * i; j <= MAX_X; j += 2 * i)
      prime[j] = false;
  }
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    for (int i = 0; i <= x; i++)
      dp[i] = false;
    dp[0] = true;
    for (int i = 0; i < n; i++) {
      for (int j = x; j >= a[i]; j--) {
        if (dp[j - a[i]]) {
          dp[j] = true;
          if (prime[j]) {
            printf(j ? "%d\n" : "NA\n", j);
            goto end;
          }
        }
      }
    }
    printf("NA\n");
  end:;
  }
}