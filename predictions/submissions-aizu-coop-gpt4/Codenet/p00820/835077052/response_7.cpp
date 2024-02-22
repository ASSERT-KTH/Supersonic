#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

ll dp[1000000];
int squares[1000];

void calculateSquares(){
    for(int i=0; i*i<1000000; i++)
        squares[i] = i*i;
}

int main() {
  int n;
  calculateSquares();
  while (~scanf("%d", &n)) {
    if (n == 0) break;
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; squares[i] <= n; i++) {
        for (int k = 1; k <= 4; k++) {
            for (int j = squares[i]; j <= n; j++) {
                dp[j] += dp[j - squares[i]];
            }
        }
    }
    printf("%lld\n", dp[n]);
  }
  return 0;
}