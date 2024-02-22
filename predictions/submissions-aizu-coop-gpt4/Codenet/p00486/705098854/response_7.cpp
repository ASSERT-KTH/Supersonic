#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// Function to calculate sum and max for a given point (x, y)
pair<long long, long long> calc(long long x, long long y, const vector<long long>& X, const vector<long long>& Y) {
    long long sum = 0, max = 0;
    for (size_t i = 0; i < X.size(); ++i) {
        long long temp = abs(X[i] - x) + abs(Y[i] - y);
        sum += temp;
        if (max < temp)
            max = temp;
    }
    return {sum, max};
}

int main() {
    long long w, h, L, HL, ox, oy, osum = 0;
    scanf("%lld %lld", &w, &h);
    scanf("%lld", &L);
    vector<long long> X(L), Y(L);
    for (long long i = 0; i < L; ++i) {
        scanf("%lld %lld", &X[i], &Y[i]);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    HL = (L + 1) / 2;
    if (L == 1) {
        printf("0\n");
        printf("%lld %lld\n", X[0], Y[0]);
    } else {
        vector<long long> oxys {X[HL - 1], X[HL], Y[HL - 1], Y[HL]};
        for (int i = 0; i < 2; ++i) {
            for (int j = 2; j < 4; ++j) {
                auto [sum, max] = calc(oxys[i], oxys[j], X, Y);
                sum *= 2;
                sum -= max;
                if (osum == 0 || osum > sum) {
                    osum = sum;
                    ox = oxys[i];
                    oy = oxys[j];
                }
            }
        }
        printf("%lld\n", osum);
        printf("%lld %lld\n", ox, oy);
    }
    return 0;
}