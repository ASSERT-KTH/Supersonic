#include <bits/stdc++.h>
using namespace std;

int main() {
    int e;
    while (scanf("%d", &e), e) {
        int m = 1000000, z = 0;
        while (z * z * z <= e) {
            int y = 0;
            while (z * z * z + y * y <= e) {
                m = min(m, e - z * z * z - y * y);
                ++y;
            }
            ++z;
        }
        printf("%d\n", m);
    }
    return 0;
}