#include <cstdio>
#define maxn 100005

typedef long long ll;

void update(ll S[], int n, int i, int x) {
    for(; i <= n; i += i & -i)
        S[i] += x;
}

int prefix_sum(ll S[], int i) {
    int ans = 0;
    for(; i > 0; i -= i & -i)
        ans += S[i];
    return ans;
}

int main() {
    int n, q;
    ll S[maxn] = {0};
    scanf("%d %d", &n, &q);
    for(int i = 0; i < q; i++) {
        bool op;
        scanf("%d", &op);
        if(op) {
            int k;
            scanf("%d", &k);
            printf("%d\n", prefix_sum(S, k));
        } else {
            int s, t, x;
            scanf("%d %d %d", &s, &t, &x);
            update(S, n, s, x);
            if(t + 1 <= n)
                update(S, n, t + 1, -x);
        }
    }
    return 0;
}