#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long w, h, L, HL, ox, oy, osum = 0LL, max = 0LL, dx, dy;
    vector<long long> XY[2], LXY[2];
    scanf("%lld %lld %lld", &w, &h, &L);
    LXY[0].resize(L);
    LXY[1].resize(L);
    for (long long f1 = 0; f1 < L; f1++) {
        scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
        XY[0].push_back(LXY[0][f1]);
        XY[1].push_back(LXY[1][f1]);
    }
    sort(XY[0].begin(), XY[0].end());
    sort(XY[1].begin(), XY[1].end());
    HL = (L + 1) / 2;
    if (L == 1) {
        printf("0\n%lld %lld\n", LXY[0][0], LXY[1][0]);
    } else {
        long long oxy[2][2] = { { XY[0][HL - 1], XY[1][HL - 1] }, { XY[0][HL], XY[1][HL] } };
        dx = (oxy[0][0] == oxy[1][0]) ? 1 : 2;
        dy = (oxy[0][1] == oxy[1][1]) ? 1 : 2;
        for (long long f2 = 0; f2 < dx; f2++) {
            for (long long f3 = 0; f3 < dy; f3++) {
                long long sum = 0LL;
                max = 0LL;
                for (long long f1 = 0; f1 < L; f1++) {
                    long long temp = abs(LXY[0][f1] - oxy[f2][0]) + abs(LXY[1][f1] - oxy[f3][1]);
                    sum += temp;
                    max = (max < temp) ? temp : max;
                }
                sum = (sum << 1) - max;
                if (osum == 0 || osum > sum) {
                    osum = sum;
                    ox = oxy[f2][0];
                    oy = oxy[f3][1];
                }
            }
        }
        printf("%lld\n%lld %lld\n", osum, ox, oy);
    }
    return 0;
}