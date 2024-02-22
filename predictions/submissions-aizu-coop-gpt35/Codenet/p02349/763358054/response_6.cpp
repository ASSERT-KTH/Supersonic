#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

// Optimized Binary Indexed Tree (Fenwick Tree) implementation
class FenwickTree {
private:
    vector<ll> BIT;
    int size;

public:
    FenwickTree(int n) {
        size = n + 1;
        BIT.resize(size);
    }

    // Update the value at index i by delta
    void update(int i, ll delta) {
        while (i < size) {
            BIT[i] += delta;
            i += i & -i;
        }
    }

    // Compute the sum of elements in the range [1, i]
    ll query(int i) {
        ll sum = 0;
        while (i > 0) {
            sum += BIT[i];
            i -= i & -i;
        }
        return sum;
    }
};

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    FenwickTree ft(n);

    for (int i = 0; i < q; i++) {
        int op;
        scanf("%d", &op);

        if (op) {
            int k;
            scanf("%d", &k);
            ll ans = ft.query(k);
            printf("%lld\n", ans);
        } else {
            int s, t, x;
            scanf("%d %d %d", &s, &t, &x);
            ft.update(s, x);
            ft.update(t + 1, -x);
        }
    }

    return 0;
}