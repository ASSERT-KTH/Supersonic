#include <bitset>
#include <deque>
#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
const int MAX_N = 300000 + 1;
bitset<MAX_N> checked;
deque<int> lists;

void sieve() {
    for (ll i = 1; i <= 300000; i += 7) {
        if (!checked[i]) {
            lists.push_back(i);
            for (ll j = i; j <= 300000; j += i)
                checked[j] = true;
        }
        if (i + 5 <= 300000 && !checked[i + 5]) {
            lists.push_back(i + 5);
            for (ll j = i + 5; j <= 300000; j += i + 5)
                checked[j] = true;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    sieve();
    while (true) {
        int n;
        cin >> n;
        if (n == 1)
            break;
        deque<int> ans;
        for (auto p : lists) {
            if (n % p == 0) {
                ans.push_back(p);
            }
        }
        cout << n << ':';
        rep(i, ans.size()) { cout << " " << ans[i]; }
        cout << endl;
    }
    return 0;
}