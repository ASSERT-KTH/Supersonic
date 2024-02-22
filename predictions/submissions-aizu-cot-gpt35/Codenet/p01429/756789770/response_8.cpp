#include <cstdio>
#include <algorithm>
#include <cstring>

const int MAX_NOTES = 2001;
const int MAX_BEAUTY = 100001;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int num_of_notes, num_of_beauty;
long long force_of_repulsion;
long long sum[MAX_BEAUTY];
long long dp[MAX_NOTES][MAX_NOTES];
int notes[MAX_NOTES];
long long beauty[MAX_BEAUTY];

long long compute(int i, int j) {
    long long lhs = sum[notes[i]];
    long long rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
    return (lhs - rhs) / force_of_repulsion;
}

int main() {
    while (scanf("%d %d %lld", &num_of_notes, &num_of_beauty, &force_of_repulsion) != EOF) {
        for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
            scanf("%d", notes + note_idx);
            notes[note_idx]--;
        }
        memset(sum, 0, sizeof(sum));
        for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
            scanf("%lld", beauty + beauty_idx);
            sum[beauty_idx] = (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
        }
        std::sort(notes, notes + num_of_notes);
        std::reverse(notes, notes + num_of_notes);
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 0; i < num_of_notes; i++) {
            int next = i + 1;
            long long compute_i_next = compute(i, next);
            for (int j = 0; j <= i; j++) {
                dp[next][j] = std::min(dp[next][j], dp[i][j] + compute_i_next);
                dp[next][i] = std::min(dp[next][i], dp[i][j] + compute(j, next));
            }
        }
        long long res = INF;
        for (int i = 0; i < num_of_notes; i++) {
            long long compute_i_num_notes = compute(i, num_of_notes - 1);
            res = std::min(dp[num_of_notes - 1][i] + compute_i_num_notes, res);
        }
        printf("%lld\n", res);
    }
    return 0;
}