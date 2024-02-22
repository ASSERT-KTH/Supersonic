#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;
typedef pair<int, int> Pr;

class Solver {
    int N, H;
    vector<int> d, h;
    const int size = 1 << 20;
    vector<int> seg_v, seg_a;
    vector<Pr> rmq;
    // ... rest of the class definition ...
};

void Solver::seg_add(int l, int r, int x, int k = 0, int a = 0, int b = size) {
    if (b <= l || r <= a)
        return;
    if (l <= a && b <= r) {
        seg_a[k] += x;
        // ... rest of the function definition ...
    }
    // ... rest of the function definition ...
}

// ... rest of the optimized code ...