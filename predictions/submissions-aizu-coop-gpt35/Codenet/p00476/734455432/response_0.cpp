#include <cstdio>
#include <algorithm>

const int INF = 1 << 28;
typedef std::pair<int, int> Pr;

void solve() {
  int N, H;
  scanf("%d %d", &N, &H);
  
  int* d = new int[N];
  int* h = new int[N - 1];
  
  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", &d[i + 1], &h[i]);
  }
  
  int* seg_a = new int[N + 1];
  int* seg_v = new int[N + 1];
  
  Pr* rmq = new Pr[N + 1];
  
  long long int res = 0;
  
  for (int i = 0; i < N; i++) {
    rmq[i] = Pr(h[i], i);
  }
  
  for (int i = 0; i < N; i++) {
    seg_a[i] = 0;
    seg_v[i] = -INF;
  }
  
  for (int i = 0; i < N; i++) {
    int idx = i;
    int val = h[i];
    
    while (idx <= N) {
      seg_a[idx] += val;
      seg_v[idx] = std::max(seg_v[idx], seg_a[idx]);
      idx += idx & -idx;
    }
    
    while (true) {
      idx = 0;
      int max_val = -INF;
      
      while (idx <= N) {
        max_val = std::max(max_val, seg_v[idx]);
        idx += idx & -idx;
      }
      
      if (max_val <= 0) {
        break;
      }
      
      idx = 0;
      
      while (idx <= N) {
        if (seg_v[idx] == max_val) {
          seg_a[idx] -= d[idx];
          seg_v[idx] -= d[idx];
          res++;
          
          if (seg_v[idx] > 0) {
            break;
          }
        }
        
        idx += idx & -idx;
      }
    }
  }
  
  printf("%lld\n", res);
  
  delete[] d;
  delete[] h;
  delete[] seg_a;
  delete[] seg_v;
  delete[] rmq;
}

int main() {
  solve();
  return 0;
}