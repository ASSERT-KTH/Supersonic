#include <iostream>
#include <vector>
using namespace std;

const int divisor = 1000000007;
const int N = 100001;
long long factmodary[N];
vector<int> fenwick_tree(N, 0);

void update(int i, int val) {
    for(; i <= N; i += i & -i)
        fenwick_tree[i] += val;
}

int prefix_sum(int i) {
    int sum = 0;
    for(; i > 0; i -= i & -i)
        sum += fenwick_tree[i];
    return sum;
}

int main() {
    factmodary[0] = 1;
    for (int i = 1; i < N; i++) {
        factmodary[i] = factmodary[i - 1] * i % divisor;
    }

    int word[N] = {0};

    for (;;) {
        int n, r;
        cin >> n;
        if (n == 0)
            break;

        cin >> r;
        for (int i = 0; i < n; i++) {
            word[i] = i + 1;
            update(i + 1, 1);
        }

        for (int i = 0; i < r; i++) {
            int s, t;
            cin >> s >> t;
            swap(word[s - 1], word[t - 1]);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            update(word[i], -1);
            ans = (ans + factmodary[n - i - 1] * prefix_sum(word[i] - 1)) % divisor;
        }
        cout << ans << "\n";
        for (int i = 0; i < n; i++) {
            update(word[i], 1);
        }
    }
    return 0;
}