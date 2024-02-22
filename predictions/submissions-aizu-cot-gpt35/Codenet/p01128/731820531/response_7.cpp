#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

struct Line {
    Point first, second;
};

bool intersect_SS(const Line &seg1, const Line &seg2) {
    double d1 = (seg1.second.x - seg1.first.x) * (seg2.first.y - seg1.first.y) - (seg1.second.y - seg1.first.y) * (seg2.first.x - seg1.first.x);
    double d2 = (seg1.second.x - seg1.first.x) * (seg2.second.y - seg1.first.y) - (seg1.second.y - seg1.first.y) * (seg2.second.x - seg1.first.x);
    double d3 = (seg2.second.x - seg2.first.x) * (seg1.first.y - seg2.first.y) - (seg2.second.y - seg2.first.y) * (seg1.first.x - seg2.first.x);
    double d4 = (seg2.second.x - seg2.first.x) * (seg1.second.y - seg2.first.y) - (seg2.second.y - seg2.first.y) * (seg1.second.x - seg2.first.x);

    return (d1 * d2 < 0) && (d3 * d4 < 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        Line s;
        cin >> s.first.x >> s.first.y >> s.second.x >> s.second.y;

        vector<pair<Point, bool>> c;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            Line t;
            int o, l;
            cin >> t.first.x >> t.first.y >> t.second.x >> t.second.y >> o >> l;

            if (intersect_SS(s, t)) {
                c.push_back(make_pair(Point(), (o ^ l)));
                c.back().first.x = (s.first.x * (t.second.y - t.first.y) * (t.second.x - t.first.x) + (s.first.y - t.first.y) * (t.second.x - t.first.x) * t.first.x - (s.first.x - t.first.x) * (t.second.x - t.first.x) * t.first.y) / ((s.second.y - s.first.y) * (t.second.x - t.first.x) - (s.second.x - s.first.x) * (t.second.y - t.first.y));