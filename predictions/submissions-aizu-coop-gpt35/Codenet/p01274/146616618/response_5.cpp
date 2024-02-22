#include <iostream>
#include <vector>
#include <climits>
#define N 100000
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

int main() {
  int n, m;
  int hp[101];
  
  while (cin >> n, n) {
    for (int i = 0; i < n; i++)
      cin >> hp[i];

    P mg[2][101]; // Using array instead of vector for fixed-size spells
    cin >> m;
    
    for (int i = 0; i < m; i++) {
      string name, type;
      int cost, dam;
      cin >> name >> cost >> type >> dam;
      
      if (dam)
        mg[type == "All"][i] = P(dam, cost); // Storing in the array directly
    }
    
    int dp[2][N + 10];
    for (int i = 0; i < 2; i++)
      for (int j = 1; j < N + 10; j++)
        dp[i][j] = INT_MAX; // Initialize with a maximum value

    for (int k = 0; k < 2; k++) {
      for (auto& spell : mg[k]) {
        if (spell.first == 0) // Skip empty spells
          continue;

        int damage = spell.first;
        int cost = spell.second;

        int range = (N / damage + 1) * damage; // Compute range once
        for (int j = damage; j <= range; j += damage) {
          dp[k][min(N, j)] = min(dp[k][min(N, j)], dp[k][j - damage] + cost);
        }
      }
    }

    for (int i = 0; i < 2; i++) {
      for (int j = N; j >= 0; j--) {
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
      }
    }

    ll ans = INT_MAX;
    for (int i = 0; i <= N; i++) {
      ll cost = dp[1][i];
      for (int j = 0; j < n; j++)
        cost += dp[0][max(0, hp[j] - i)];
      ans = min(ans, cost);
    }
    
    cout << ans << endl;
  }
  
  return 0;
}