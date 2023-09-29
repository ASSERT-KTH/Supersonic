#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct{
    double x, y;
} Point;

bool compare(Point a, Point b){
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

double cross_product(Point O, Point A, Point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P){
    int n = P.size(), k = 0;
    vector<Point> H(2*n);
    sort(P.begin(), P.end(), compare);

    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross_product(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    for (int i = n-1, t = k+1; i > 0; --i) {
        while (k >= t && cross_product(H[k-2], H[k-1], P[i-1]) <= 0) k--;
        H[k++] = P[i-1];
    }

    H.resize(k-1);
    return H;
}

int main(){
    int N;
    while (cin >> N && N){
        vector<Point> points(N);
        for(int i = 0; i < N; ++i){
            char ch;
            cin >> points[i].x >> ch >> points[i].y;
        }
        vector<Point> res = convex_hull(points);
        cout << N - res.size() << endl;
    }
    return 0;
}