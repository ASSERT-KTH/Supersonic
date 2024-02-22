#include <iostream>
#include <cmath>
#include <array>
#include <string>

using namespace std;

class Point3d {
public:
    double x, y, z;
    constexpr Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    constexpr Point3d operator+(const Point3d &a) const { return {x + a.x, y + a.y, z + a.z}; }
    constexpr Point3d operator-(const Point3d &a) const { return {x - a.x, y - a.y, z - a.z}; }
    constexpr Point3d operator*(const double &d) const { return {x * d, y * d, z * d}; }
    constexpr Point3d operator/(const double &d) const { return {x / d, y / d, z / d}; }
    constexpr bool operator<(const Point3d &p) const {
        double EPS = 1e-7;
        auto equals = [](double a, double b) { return abs(a - b) < EPS; };
        return !equals(x, p.x) ? x < p.x : (!equals(y, p.y) ? y < p.y : z < p.z);
    }
    constexpr bool operator==(const Point3d &p) const {
        double EPS = 1e-7;
        auto equals = [](double a, double b) { return abs(a - b) < EPS; };
        return equals(x, p.x) && equals(y, p.y) && equals(z, p.z);
    }
};

using Vector3d = Point3d;
using Line3d = Vector3d[2];

constexpr double dot(const Point3d &a, const Point3d &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

constexpr Vector3d cross(const Point3d &a, const Point3d &b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

constexpr double norm(const Point3d &p) {
    return p.x * p.x + p.y * p.y + p.z * p.z;
}

constexpr double abs(const Point3d &p) { return sqrt(norm(p)); }

bool on_line3d(const Line3d &line, const Point3d &p) {
    double EPS = 1e-7;
    auto equals = [](double a, double b) { return abs(a - b) < EPS; };
    return equals(abs(cross(p - line[0], line[1] - line[0])), 0);
}

bool on_segment3d(const Line3d &seg, const Point3d &p) {
    if (!on_line3d(seg, p))
        return false;
    std::array<double, 3> dist = {abs(seg[1] - seg[0]), abs(p - seg[0]), abs(p - seg[1])};
    double EPS = 1e-7;
    auto equals = [](double a, double b) { return abs(a - b) < EPS; };
    return equals(dist[0], dist[1] + dist[2]);
}

// ... rest of the code ...

int main() {
    // ... rest of the code ...
    const std::string Y = "HIT", N = "MISS";
    // ... rest of the code ...
    cout << (point_on_the_triangle3d(tri[0], tri[1], tri[2], cp) ? N : Y) << '\n';
    return 0;
}