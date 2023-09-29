#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
int n, t, cnt[MAXN];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        cnt[t]++;
    }
    for(int i = 0; i < MAXN; i++) {
        while(cnt[i]--) printf("%d ", i);
    }
    return 0;
}