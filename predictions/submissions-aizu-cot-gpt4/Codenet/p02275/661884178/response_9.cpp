#include <iostream>
#include <cstdio>
#define SIZE 10001
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

inline void loop(int n, void (*f)(int)) {
    for (int i = 0; i < n; i++) {
        f(i);
    }
}

int main() {
    fastIO;
    int n;
    cin >> n;
    int min = 2000000, t, A[SIZE]{};
    loop(n, [&](int) {
        cin >> t;
        if (t < min)
            min = t;
        A[t]++;
    });
    A[min]--;
    printf("%d", min);
    for (int i = min; i < SIZE; i++) {
        loop(A[i], [&](int) { printf(" %d", i); });
    }
    printf("\n");
    return 0;
}