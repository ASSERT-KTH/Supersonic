#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

typedef complex<double> Point;
typedef pair<Point, bool> P;

bool intersect_SS(const Point& p1, const Point& p2, const Point& q1, const Point& q2) {
    double d1 = cross(q1 - p1, p2 - p1);
    double d2 = cross(q2 - p1, p2 - p1);
    double d3 = cross(p1 - q1, q2 - q1);
    double d4 = cross(p2 - q1, q2 - q1);
    return (d1 * d2 < 0) && (d3 * d4 < 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        Point p1, p2;
        cin >> p1 >> p2;
        vector<P> c;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            Point q1, q2;
            int o, l;
            cin >> q1 >> q2 >> o >> l;
            if (intersect_SS(p1, p2, q1, q2))
                c.push_back(make_pair((p1 + p2) / 2.0, (o ^ l)));
        }
        sort(c.begin(), c.end());
        int res = 0;
        for (int i = 0; i < (int)c.size() - 1; ++i) {
            if (c[i].second != c[i + 1].second)
                ++res;
        }
        cout << res << endl;
    }

    return 0;
}