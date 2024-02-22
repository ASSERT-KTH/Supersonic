#include <cstdio>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    while (scanf("%d %d", &n, &k), n) {
        long long prev_ac = 0, ac = 0, temp;
        long long res = -LLONG_MAX;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &temp);
            
            // Calculate prefix sum
            ac += temp;
            
            // Calculate maximum sum subarray of size k
            if (i >= k) {
                res = max(res, ac - prev_ac);
                // Update prev_ac with (i-k)th prefix sum for the next iteration
                scanf("%lld", &temp);
                prev_ac += temp;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}