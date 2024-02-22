#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <cmath>

#define MOD1 1000000007
#define MOD2 1000007

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dic_op(char str[14]) {
    int mapping[256] = {0}; // Initialize mapping table with all characters as 0
    mapping['A'] = 1;
    mapping['C'] = 2;
    mapping['G'] = 3;
    mapping['T'] = 4;

    int j;
    ll f = 1;
    ll g = 0;
    for (j = 0; str[j] != '\0'; j++) {
        g += f * mapping[str[j]];
        f *= 5;
    }
    return g;
}

int main() {
    int i, j, k, l;
    int n;
    long ans = 0;
    unordered_set<int> dic;
    char opstr[7];
    char str[13];
    cin >> n;
    for (i = 0; i < n; i++) {
        scanf("%s %s", opstr, str);
        if (opstr[0] == 'i') {
            dic.insert(dic_op(str));
        } else if (opstr[0] == 'f') {
            if (dic.count(dic_op(str)) > 0)
                puts("yes");
            else
                puts("no");
            j++;
        }
    }
    return 0;
}