#include <algorithm>
#include <iostream>
#include <vector>

#define fs first
#define sc second

using namespace std;

typedef long long ll;

struct Pair {
    ll first;
    int second;
};

bool compareFirst(const Pair &a, const Pair &b) {
    return a.first < b.first;
}

bool compareSecond(const Pair &a, const Pair &b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Pair> p(n), b(n);
    vector<ll> a(n);
    vector<bool> use(n, false);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i].fs;
        p[i] = {a[i], i};
        b[i].sc = i;
    }

    sort(p.begin(), p.end(), compareFirst);
    sort(b.begin(), b.end());

    int ans = 0, id = 0, num = 0;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        if (!use[b[i].sc]) {
            sum += a[b[i].sc];
            use[b[i].sc] = true;
            num++;
        }
        while (id < n && p[id].fs <= b[i].fs) {
            if (!use[p[id].sc]) {
                sum += p[id].fs;
                use[p[id].sc] = true;
                num++;
            }
            id++;
        }
        while (id < n) {
            if (!use[p[id].sc]) {
                if (sum + p[id].fs > (num + 1) * b[i].fs)
                    break;
                sum += p[id].fs;
                use[p[id].sc] = true;
                num++;
            }
            id++;
        }
        if (sum <= num * b[i].fs)
            ans = max(ans, num);
        sum -= a[b[i].sc];
        num--;
    }

    cout << ans << endl;
    return 0;
}