#include <stdio.h>
#include <algorithm>

struct Data {
    long long size;
    long long value;
};

bool cmp(const Data &a, const Data &b) {
    return a.size == b.size ? a.value < b.value : a.size < b.size;
}

int main(void) {
    long long N;
    scanf("%lld", &N);

    Data art[N];
    for (long long i = 0; i < N; ++i) {
        scanf("%lld %lld", &art[i].size, &art[i].value);
    }

    std::sort(art, art + N, cmp);

    long long min_size = art[0].size;
    long long sum_value = art[0].value;
    long long ans = art[0].value;

    for (long long i = 1; i < N; ++i) {
        long long value = art[i].value;
        long long size = art[i].size;

        long long tmp = sum_value + value - (size - min_size);
        if (tmp < value) {
            ans = std::max(ans, value);
            sum_value = value;
            min_size = size;
        } else {
            ans = std::max(ans, tmp);
            sum_value += value;
        }
    }

    printf("%lld\n", ans);

    return 0;
}