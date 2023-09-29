#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>

#define MOD1 1000000007;
#define MOD2 1000007

typedef long long ll;

using namespace std;

const int maxn = (1 << 20);
const int maxlen = 13;

int n;
char opstr[7];
char str[13];

unordered_map<ll, int> dic;

ll pow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}

int dic_op(char str[]) {
    int j;
    ll f = 1;
    ll g = 0;
    for (j = 0; str[j]; j++) {
        if (str[j] == 'A')
            g += f * 1;
        else if (str[j] == 'C')
            g += f * 2;
        else if (str[j] == 'G')
            g += f * 3;
        else if (str[j] == 'T')
            g += f * 4;
        else
            break;
        f *= 5;
    }
    return g;
}

int main() {
    int i, j, k, l;

    cin >> n;

    for (i = 0; i < n; i++) {
        scanf("%s %s", opstr, str);
        int hash_val = dic_op(str);
        if (opstr[0] == 'i') {
            dic[hash_val] = 1;
        } else if (opstr[0] == 'f') {
            if (dic.count(hash_val)) {
                puts("yes");
            } else {
                puts("no");
            }
        }
    }

    return 0;
}