#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    vector<pii> p(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        p[i] = make_pair(a[i], i);
    }
    
    sort(p.begin(), p.end());
    
    int ans = 0;
    int sum = 0;
    int id = 0;
    int num = 0;
    
    for (int i = 0; i < n; i++) {
        sum += a[i];
        num++;
        
        while (id < n && p[id].first <= b[i]) {
            if (a[p[id].second] <= b[i]) {
                sum += a[p[id].second];
                num++;
            }
            id++;
        }
        
        if (sum <= num * b[i]) {
            ans = max(ans, num);
        }
        
        sum -= a[i];
        num--;
    }
    
    cout << ans << endl;
    
    return 0;
}