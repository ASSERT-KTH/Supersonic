#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> S;
int n, q;

ll getSum(int idx) {
    ll sum = 0;
    while (idx >= 0) {
        sum += S[idx];
        idx = (idx & (idx + 1)) - 1;
    }
    return sum;
}

void update(int idx, int val) {
    while (idx < n) {
        S[idx] += val;
        idx = idx | (idx + 1);
    }
}

int main() {
    scanf("%d%d", &n, &q);
    S.resize(n, 0);

    for (int i = 0; i < q; i++) {
        int op;
        scanf("%d", &op);
        if (op) {
            int k;
            scanf("%d", &k);
            printf("%lld\n", getSum(k - 1));
        } else {
            int s, t, x;
            scanf("%d%d%d", &s, &t, &x);
            update(s - 1, x);
            update(t, -x);
        }
    }

    return 0;
}