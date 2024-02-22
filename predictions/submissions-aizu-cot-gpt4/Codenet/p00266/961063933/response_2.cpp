#include <iostream>
using namespace std;
const int divisor = 1000000007;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long factmodary[100001];
    long long fact = 1;
    for (int i = 1; i <= 100000; i++) {
        fact *= i;
        fact %= divisor;
        factmodary[i] = fact;
    }
    int word[100000];
    int count[100000];
    int N, R;
    while (cin >> N && N != 0) {
        cin >> R;
        for (int i = 0; i < N; i++) {
            word[i] = i + 1;
            count[i] = 0;
        }
        for (int i = 0; i < R; i++) {
            int s, t;
            cin >> s >> t;
            int tmp = word[s - 1];
            word[s - 1] = word[t - 1];
            word[t - 1] = tmp;
            count[s - 1]++;
            count[t - 1]++;
        }
        long long ans = factmodary[N - 1] * (word[0] - 1);
        for (int i = 1; i < N; i++) {
            int facttime = word[i] - 1;
            facttime -= count[i];
            ans += factmodary[N - (i + 1)] * facttime;
            ans %= divisor;
        }
        cout << ans << "\n";
    }
    return 0;
}