#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 1e6+5; // Maximum size for array, adjust according to problem constraints

ll tree[2*MAX_N], lazy[2*MAX_N];

void build(ll arr[], int n) {
    // Build the segment tree
    for (int i=0; i<n; i++)
        tree[n+i] = arr[i];
    for (int i=n-1; i>0; --i)
        tree[i] = tree[i<<1] + tree[i<<1 | 1];
}

void update(int n, int l, int r, int val) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) tree[l] += val, lazy[l] += val, l++;
        if (r&1) --r, tree[r] += val, lazy[r] += val;
    }
}

void push(int n, int p) {
    // Push the lazy value down to the children
    for (int s = n; s > 0; s >>= 1) {
        if (lazy[p] != 0) {
            tree[p] += lazy[p];
            if (p < s) {
                lazy[p<<1] += lazy[p];
                lazy[p<<1|1] += lazy[p];
            }
            lazy[p] = 0;
        }
        p >>= 1;
    }
}

ll query(int n, int l, int r) {
    ll res = 0;
    push(n, l+n);
    push(n, r+n-1);
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += tree[l++];
        if (r&1) res += tree[--r];
    }
    return res;
}

int main() {
    int n, q;
    cin >> n >> q;

    ll arr[MAX_N] = {0}; // Initialize array to zero
    build(arr, n);

    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            update(n, s-1, t, x);
        } else {
            int s;
            cin >> s;
            cout << query(n, s-1, s) << "\n";
        }
    }
    return 0;
}