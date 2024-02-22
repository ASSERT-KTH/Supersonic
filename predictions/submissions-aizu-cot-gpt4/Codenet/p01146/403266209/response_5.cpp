#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::unordered_set;

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    unordered_set<int> rei;
    rei.insert(a), rei.insert(h);
    std::vector<int> b(n * n, INT_MAX), x(n * n, INT_MAX);
    rei.insert(a), rei.insert(h);
    for(int i=0; i<l; i++){
        cin >> t1;
        rei.insert(t1);
    }
    for(int i=0; i<k; i++){
        cin >> t1 >> t2 >> t3;
        b[t1*n+t2] = b[t2*n+t1] = t3;
    }
    for(int o=0; o<n; o++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                b[i*n+j] = min(b[i*n+j], b[i*n+o] + b[o*n+j]);
            }
        }
    }
    for(int i=0; i<n; i++){
        if (rei.count(i)){
            for(int j=0; j<n; j++){
                if (rei.count(j)){
                    if (b[i*n+j] <= m)
                        x[i*n+j] = b[i*n+j];
                }
            }
        }
    }
    for(int o=0; o<n; o++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                x[i*n+j] = min(x[i*n+j], x[i*n+o] + x[o*n+j]);
            }
        }
    }
    if (x[a*n+h] >= INT_MAX)
      cout << "Help!" << endl;
    else if (x[a*n+h] < m)
      cout << x[a*n+h] << endl;
    else
      cout << x[a*n+h] * 2 - m << endl;
  }
}