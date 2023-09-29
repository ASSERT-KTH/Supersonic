#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10001;
int n, freq[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int min_val = 2e6+5;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        min_val = min(min_val, t);
        freq[t]++;
    }
    printf("%d ", min_val);
    for(int i = min_val+1; i < MAXN; i++) {
        for(int j = 0; j < freq[i]; j++) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}