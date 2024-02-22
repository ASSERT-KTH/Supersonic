#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> Point;
typedef std::pair<Point, bool> Intersection;

bool intersect_SS(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    int d1 = (p3.first - p1.first) * (p2.second - p1.second) - (p3.second - p1.second) * (p2.first - p1.first);
    int d2 = (p4.first - p1.first) * (p2.second - p1.second) - (p4.second - p1.second) * (p2.first - p1.first);
    int d3 = (p1.first - p3.first) * (p4.second - p3.second) - (p1.second - p3.second) * (p4.first - p3.first);
    int d4 = (p2.first - p3.first) * (p4.second - p3.second) - (p2.second - p3.second) * (p4.first - p3.first);
    return (d1 * d2 < 0) && (d3 * d4 < 0);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while (T--) {
        Point s1, s2;
        std::cin >> s1.first >> s1.second >> s2.first >> s2.second;
        
        int n;
        std::cin >> n;
        
        std::vector<Intersection> intersections;
        for (int i = 0; i < n; ++i) {
            Point t1, t2;
            int o, l;
            std::cin >> t1.first >> t1.second >> t2.first >> t2.second >> o >> l;
            if (intersect_SS(s1, s2, t1, t2)) {