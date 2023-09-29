#include <cstdio>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);
    int* S = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &S[i]);
    }
    std::sort(S, S+n);
    int cnt = 0;
    int q;
    scanf("%d", &q);
    while(q--) {
        int T;
        scanf("%d", &T);
        if(std::binary_search(S, S+n, T)) ++cnt;
    }
    printf("%d\n", cnt);
    delete[] S;
    return 0;
}