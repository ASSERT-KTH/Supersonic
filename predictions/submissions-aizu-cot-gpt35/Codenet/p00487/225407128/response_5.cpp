#include <iostream>
#define fs first
#define sc second
using namespace std;

int n;
pair<long long, int> p[300010], b[300010];
long long a[300010];
bool use[300010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i].fs;
    p[i] = make_pair(a[i], i);
    b[i].sc = i;
    use[i] = false;
  }
  
  sort(p, p + n);
  sort(b, b + n);
  
  int ans = 0;
  long long sum = 0;
  int id = 0, num = 0;
  
  for (int i = 0; i < n; i++) {
    if (!use[b[i].sc]) {
      sum += a[b[i].sc];
      use[b[i].sc] = true;
      num++;
    }
    
    int numPlusOne = num + 1;
    
    while (id < num && p[id].fs <= b[i].fs) {
      if (!use[p[id].sc]) {
        sum += p[id].fs;
        use[p[id].sc] = true;
        num++;
      }
      id++;
    }
    
    while (id < numPlusOne) {
      if (!use[p[id].sc]) {
        if (sum > num * b[i].fs - p[id].fs)
          break;
        sum += p[id].fs;
        use[p[id].sc] = true;
        num++;
      }
      id++;
    }
    
    if (sum <= num * b[i].fs)
      ans = max(ans, num);
    
    sum -= a[b[i].sc];
    num--;
  }
  
  cout << ans << endl;
}