#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    double x, y;
};

struct Segment {
    Point start, end;
};

bool intersect(const Segment& s1, const Segment& s2) {
    double d1 = (s1.end.x - s1.start.x) * (s2.start.y - s1.start.y) - (s1.end.y - s1.start.y) * (s2.start.x - s1.start.x);
    double d2 = (s1.end.x - s1.start.x) * (s2.end.y - s1.start.y) - (s1.end.y - s1.start.y) * (s2.end.x - s1.start.x);
    double d3 = (s2.end.x - s2.start.x) * (s1.start.y - s2.start.y) - (s2.end.y - s2.start.y) * (s1.start.x - s2.start.x);
    double d4 = (s2.end.x - s2.start.x) * (s1.end.y - s2.start.y) - (s2.end.y - s2.start.y) * (s1.end.x - s2.start.x);
    return (d1 * d2 < 0) && (d3 * d4 < 0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    while (T--) {
        Segment s;
        cin >> s.start.x >> s.start.y >> s.end.x >> s.end.y;
        
        int n;
        cin >> n;
        
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            Segment t;
            int o, l;
            cin >> t.start.x >> t.start.y >> t.end.x >> t.end.y >> o >> l;
            
            if (intersect(s, t)) {
                if (o ^ l) {
                    res++;
                }
            }
        }
        
        cout << res << endl;
    }
    