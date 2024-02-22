#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Point {
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Segment {
    Point p1, p2;
};

bool operator<(const Segment &s1, const Segment &s2) {
    return s1.p2 < s2.p2;
}

Point crosspoint(const Segment &s1, const Segment &s2) {
    double A = (s1.p2.x - s1.p1.x) * (s2.p2.y - s2.p1.y) - (s1.p2.y - s1.p1.y) * (s2.p2.x - s2.p1.x);
    double B = (s1.p2.x - s1.p1.x) * (s1.p2.y - s2.p1.y) - (s1.p2.y - s1.p1.y) * (s1.p2.x - s2.p1.x);
    double t = B / A;
    return Point(s2.p1.x + (s2.p2.x - s2.p1.x) * t, s2.p1.y + (s2.p2.y - s2.p1.y) * t);
}

const string MANY = "Many";
const string NONE = "None";

void compute(vector<Segment> &vec) {
    if (vec.size() <= 2) {
        cout << MANY << endl;
        return;
    }

    vector<Segment> candidateLines(10);
    int n = vec.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((vec[i].p2.x - vec[i].p1.x) * (vec[j].p2.y - vec[j].p1.y) - (vec[i].p2.y - vec[i].p1.y) * (vec[j].p2.x - vec[j].p1.x) == 0) {
                double e1x = vec[i].p2.x - vec[i].p1.x;
                double e1y = vec[i].p2.y - vec[i].p1.y;
                double e2x = vec[j].p2.x - vec[j].p1.x;
                double e2y = vec[j].p2.y - vec[j].p1.y;
                double len1 = sqrt(e1x * e1x + e1y * e1y);
                double len2 = sqrt(e2x * e2x + e2y * e2y);
                double ex1 = e1x / len1;
                double ey1 = e1y / len1;
                double ex2 = e2x / len2;
                double ey2 = e2y / len2;
                double cp1x = vec[i].p1.x + ex1 * 100;
                double cp1y = vec[i].p1.y + ey1 * 100;
                double cp2x = vec[j].p1.x + ex1 * 100;
                double cp2y = vec[j].p1.y + ey1 * 100;
                double mpx = (cp1x + cp2x) / 2.0;
                double mpy = (cp1y + cp2y) / 2.0;