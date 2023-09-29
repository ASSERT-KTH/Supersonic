#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using std::string;
using std::max;
using std::cin;
using std::cout;

typedef long long ll;

string S;
int p, ch[1 << 8];

ll bnf();
ll calc(int c);

ll getNum() {
    ll res = 0;
    while (std::isdigit(S[p]))
        res = res * 10 + S[p++] - '0';
    return res;
}

ll get(ll &a, ll b, char c) {
    switch(c) {
        case '+': return a += b;
        case '-': return a -= b;
        case '*': return a *= b;
    }
    return a;
}

ll calc(int c) {
    ll res;
    if (S[p] == '(')
        p++, res = bnf(), p++;
    else
        res = getNum();
    
    while (p < S.size() && S[p] != ')' && ch[S[p]] > c)
        get(res, calc(ch[S[p++]]), S[p-1]);
    return res;
}

ll bnf() {
    ll res = calc(-1);
    while (p < S.size() && S[p] != ')')
        get(res, calc(ch[S[p++]]), S[p-1]);
    return res;
}

int main() {
    cin >> S;
    ll res = bnf();
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) {
                ch['+'] = i, ch['-'] = j, ch['*'] = k;
                p = 0;
                res = max(res, calc(-100));
            }
    cout << res << "\n";
    return 0;
}