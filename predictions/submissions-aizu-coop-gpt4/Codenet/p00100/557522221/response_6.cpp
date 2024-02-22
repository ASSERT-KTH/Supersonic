#include <stdio.h>
#include <map>
using namespace std;

int main() {
    int n, i;
    long long p, q;
    while (scanf("%d", &n), n) {
        map<int, long long> m;
        int s = 0;
        while (n--) {
            scanf("%d %lld %lld", &i, &p, &q);
            m[i] += p * q;
        }
        for (auto& it : m) {
            if (it.second >= 1000000) {
                s = 1;
                printf("%d\n", it.first);
            }
        }
        if (!s)
            printf("NA\n");
    }
    return 0;
}