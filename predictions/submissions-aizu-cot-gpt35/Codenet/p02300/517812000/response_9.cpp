#include <cstdio>

class Point {
public:
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    bool operator<(const Point &p) const {
        return y < p.y || (y == p.y && x < p.x);
    }
};

inline bool direct(const Point &base, const Point &a, const Point &b) {
    return (a.x - base.x) * (b.y - base.y) - (a.y - base.y) * (b.x - base.x) < 0;
}

int main() {
    size_t n;
    size_t k = 2;
    Point P[100000];
    Point H[200000];

    scanf("%zu", &n);
    for (size_t i = 0; i < n; ++i) {
        scanf("%d%d", &P[i].x, &P[i].y);
    }

    std::sort(P, P + n);

    H[0] = P[0];
    H[1] = P[1];
    for (size_t i = 0; i < n - 2; ++i) {
        while (k >= 2 && direct(H[k - 2], H[k - 1], P[i + 2]))
            k--;
        H[k++] = P[i + 2];
    }

    H[k++] = P[n - 2];
    for (size_t i = n; i > 2; i--) {
        while (k >= 2 && direct(H[k - 2], H[k - 1], P[i - 3]))
            k--;
        H[k++] = P[i - 3];
    }

    printf("%zu\n", k - 1);
    for (size_t i = 0; i < k - 1; ++i) {
        printf("%d %d\n", H[i].x, H[i].y);
    }

    return 0;
}