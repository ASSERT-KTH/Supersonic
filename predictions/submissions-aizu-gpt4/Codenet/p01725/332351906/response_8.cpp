#include <iostream>
#include <string>

typedef long long ll;
std::string S;
int p, ch[1 << 8];

ll getNum() {
    ll res = 0;
    while (p < S.size() && S[p] >= '0' && S[p] <= '9') {
        res = res * 10 + S[p++] - '0';
    }
    return res;
}

ll calc(int c);
ll bnf();

ll get(ll &a, ll b, char c) {
    if (c == '+')
        a += b;
    else if (c == '-')
        a -= b;
    else if (c == '*')
        a *= b;
    return a;
}

ll calc(int c) {
    ll res;
    if (p < S.size() && S[p] == '(') {
        p++;
        res = bnf();
        p++;
    } else {
        res = getNum();
    }
    while (p < S.size() && S[p] != ')' && ch[S[p]] >= c) {
        char t = S[p++];
        get(res, calc(ch[t]), t);
    }
    return res;
}

ll bnf() {
    ll res = calc(0);
    while (p < S.size() && S[p] != ')') {
        char t = S[p++];
        get(res, calc(ch[t]), t);
    }
    return res;
}

int main() {
    std::cin >> S;
    ll res = bnf();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                ch['+'] = i, ch['-'] = j, ch['*'] = k;
                p = 0;
                res = std::max(res, bnf());
            }
        }
    }
    std::cout << res << '\n';
    return 0;
}