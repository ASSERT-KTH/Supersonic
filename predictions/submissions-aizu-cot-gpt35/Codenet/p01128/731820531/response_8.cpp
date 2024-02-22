#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>
using namespace std;

typedef complex<double> Point;
typedef pair<Point, bool> Pint;
typedef pair<Point, Point> Seg;

bool intersect_SS(const Seg& seg1, const Seg& seg2) {
    double c1 = cross(seg1.second - seg1.first, seg2.first - seg1.first);
    double c2 = cross(seg1.second - seg1.first, seg2.second - seg1.first);
    if ((c1 < 0 && c2 < 0) || (c1 > 0 && c2 > 0)) {
        return false;
    }
    double c3 = cross(seg2.second - seg2.first, seg1.first - seg2.first);
    double c4 = cross(seg2.second - seg2.first, seg1.second - seg2.first);
    if ((c3 < 0 && c4 < 0) || (c3 > 0 && c4 > 0)) {
        return false;
    }
    return true;
}

Point ip_SS(const Seg& seg1, const Seg& seg2) {
    double a = cross(seg1.second - seg1.first, seg2.first - seg1.first);
    double b = cross(seg1.second - seg1.first, seg2.second - seg1.first);
    double t = a / (a + b);
    return seg2.first + t * (seg2.second - seg2.first);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Seg s;
        cin >> s.first >> s.second;
        double angle = -arg(s.second - s.first);
        s.first *= polar(1.0, angle);
        s.second *= polar(1.0, angle);
        vector<Pint> c;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            Seg t;
            int o, l;
            cin >> t.first >> t.second >> o >> l;
            t.first *= polar(1.0, angle);
            t.second *= polar(1.0, angle);
            if (intersect_SS(s, t)) {
                c.push_back(make_pair(ip_SS(s, t), (o ^ l)));
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