#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> Point;
typedef pair<Point, bool> Pair;

bool comparePairs(const Pair& p1, const Pair& p2) {
    return p1.second < p2.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        Point p1, p2;
        cin >> p1.first >> p1.second >> p2.first >> p2.second;
        
        int n;
        cin >> n;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            Point t1, t2;
            int o, l;
            cin >> t1.first >> t1.second >> t2.first >> t2.second >> o >> l;
            
            bool intersect = false;
            if ((t1.second - p1.second) * (t1.second - p2.second) < 0 &&
                (p1.second - t1.second) * (p1.second - t2.second) < 0) {
                intersect = true;
            }
            
            if (intersect && o != l) {
                res++;
            }
        }
        
        cout << res << endl;
    }
    
    return 0;
}