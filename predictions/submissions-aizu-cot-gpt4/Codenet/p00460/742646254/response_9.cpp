#include <iostream>
#include <vector>

template <class T1, class T2> 
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}

template <class T1, class T2> 
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;

constexpr int inf = 1 << 29;
int dp[55][3030];

int main() {
  constexpr int MOD = 100000;
  int N, M, S;
  while(std::cin >> N >> M >> S && (N | M | S)){
    for(int i=0; i<55; i++)
      for(int j=0; j<3030; j++)
        dp[i][j] = 0;
        
    dp[0][0] = 1;
    
    for(int add=1; add <= M; add++) {
      for(int currIndex=N*N; currIndex >=1; currIndex--){
        for(int currSum=add; currSum <= S; currSum++){
          dp[currIndex][currSum] = (dp[currIndex][currSum] + dp[currIndex - 1][currSum - add]) % MOD;
        }
      }
    }
    std::cout << dp[N*N][S] << std::endl;
  }
  return 0;
}