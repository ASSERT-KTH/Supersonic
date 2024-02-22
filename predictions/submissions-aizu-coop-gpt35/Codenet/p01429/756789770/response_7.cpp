#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;

const static int tx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const static int ty[] = {-1, -1, 0, 1, 1, 1, 0, -1};
static const double EPS = 1e-8;

ll compute(int i, int j, ll* sum, ll force_of_repulsion) {
    ll lhs = sum[i];
    ll rhs = (j - 1 < 0 ? 0 : sum[j - 1]);
    return (lhs - rhs) / force_of_repulsion;
}

int main() {
    int num_of_notes, num_of_beauty;
    ll force_of_repulsion;
    while (~scanf("%d %d %lld", &num_of_notes, &num_of_beauty, &force_of_repulsion)) {
        int notes[2001];
        for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
            scanf("%d", notes + note_idx);
            notes[note_idx]--;
        }

        ll sum[100001] = {0};
        ll beauty[100001];

        for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
            scanf("%lld", beauty + beauty_idx);
            sum[beauty_idx] = (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
        }

        sort(notes, notes + num_of_notes, greater<int>());

        ll dp[2001][2001];
        for (int i = 0; i <= num_of_notes; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = LINF;
            }
        }

        dp[0][0] = 0;
        for (int i = 0; i < num_of_notes; i++) {
            int next = i + 1;
            for (int j = 0; j <= i; j++) {
                dp[next][j] = min(dp[next][j], dp[i][j] + compute(i, next, sum, force_of_repulsion));
                dp[next][i] = min(dp[next][i], dp[i][j] + compute(j, next, sum, force_of_repulsion));
            }
        }

        ll res = LINF;
        for (int i = 0; i < num_of_notes; i++) {
            res = min(dp[num_of_notes][i] + compute(i, num_of_notes - 1, sum, force_of_repulsion), res);
        }

        printf("%lld\n", res);
    }
    return 0;
}