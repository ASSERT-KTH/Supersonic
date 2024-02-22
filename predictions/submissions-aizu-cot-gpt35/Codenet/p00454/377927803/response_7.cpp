#include <iostream>
#include <set>
#include <queue>
using namespace std;

int w, h;
int n;
int x1[1005], x2[1005];
int y1[1005], y2[1005];
bool fld[1005 * 6 + 2];

int compress(int *x1, int *x2, int w) {
  set<int> xs;
  for (int i = 0; i < n; ++i) {
    for (int d = -1; d <= 1; ++d) {
      int tx1 = x1[i] + d, tx2 = x2[i] + d;
      if (0 <= tx1 && tx1 <= w)
        xs.insert(tx1);
      if (0 <= tx2 && tx2 <= w)
        xs.insert(tx2);
    }
  }
  int idx = 0;
  for (int x : xs) {
    x1[idx] = x;
    x2[idx] = x;
    idx++;
  }
  return xs.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  while (cin >> w >> h, w) {
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
      cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    
    w = compress(x1, x2, w);
    h = compress(y1, y2, h);
    
    memset(fld, 0, sizeof(fld));
    
    for (int i = 0; i < n; ++i) {
      for (int y = y1[i]; y <= y2[i] - 1; ++y) {
        for (int x = x1[i]; x <= x2[i] - 1; ++x) {
          fld[y * w + x] = true;
        }
      }
    }
    
    int ans = 0;
    
    for (int i = 0; i < h * w; ++i) {
      if (fld[i])
        continue;
      
      ans++;
      
      queue<int> q;
      q.push(i);
      fld[i] = true;
      
      while (!q.empty()) {
        int p = q.front();
        q.pop();
        
        int y = p / w;
        int x = p % w;
        
        if (y > 0 && !fld[(y - 1) * w + x]) {
          fld[(y - 1) * w + x] = true;
          q.push((y - 1) * w + x);
        }
        if (y < h - 1 && !fld[(y + 1) * w + x]) {
          fld[(y + 1) * w + x] = true;
          q.push((y + 1) * w + x);
        }
        if (x > 0 && !fld[y * w + (x - 1)]) {
          fld[y * w + (x - 1)] = true;
          q.push(y * w + (x - 1));
        }
        if (x < w - 1 && !fld[y * w + (x + 1)]) {
          fld[y * w + (x + 1)] = true;
          q.push(y * w + (x + 1));
        }
      }
    }
    
    cout << ans << endl;
  }
}