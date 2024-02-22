#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;

typedef complex<double> Point;
typedef pair<Point, bool> PointBool;
typedef pair<Point, Point> Segment;

bool intersectSS(const Segment& seg1, const Segment& seg2) {
    const auto& p1 = seg1.first;
    const auto& p2 = seg1.second;
    const auto& p3 = seg2.first;
    const auto& p4 = seg2.second;
    auto d1 = imag((p2 - p1) * conj(p3 - p1)) * imag((p2 - p1) * conj(p4 - p1));
    auto d2 = imag((p4 - p3) * conj(p1 - p3)) * imag((p4 - p3) * conj(p2 - p3));
    if (d1 == 0 && d2 == 0) {
        return min(p1, p2) <= max(p3, p4) && min(p3, p4) <= max(p1, p2);
    }
    return d1 <= 0 && d2 <= 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        Segment s;
        cin >> s.first >> s.second;
        double angle = arg(s.second - s.first);
        s.second *= polar(1.0, -angle);
        vector<PointBool> c;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            Segment t;
            int o, l;
            cin >> t.first >> t.second >> o >> l;
            t.first *= polar(1.0, -angle);
            t.second *= polar(1.0, -angle);
            if (intersectSS(s, t)) {
                c.emplace_back(intersectLL(s, t), (o ^ l));
            }
        }
        sort(c.begin(), c.end());
        int res = 0;
        for (int i = 0; i < c.size() - 1; ++i) {
            if (c[i].second != c[i + 1].second) {
                ++res;
            }
        }
        cout << res << endl;
    }
    return 0;
}