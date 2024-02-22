#include <iostream>
using namespace std;

const int MAX_K = 100;

int main() {
  int N, K, i, j, S[MAX_K], B;
  
  while (cin >> N >> K, N || K) {
    for (i = 0; i < K; ++i)
      cin >> S[i];
      
    bool a = true;
    
    for (i = 0; i < N; ++i) {
      for (j = 0; j < K; ++j) {
        cin >> B;
        S[j] -= B;
        if (S[j] < 0) {
          a = false;
          break;
        }
      }
    }
    
    cout << (a ? "Yes" : "No") << endl;
  }
}