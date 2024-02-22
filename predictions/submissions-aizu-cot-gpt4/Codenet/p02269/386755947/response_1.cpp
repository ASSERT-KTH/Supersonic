#include <iostream>
using namespace std;

bool d[33554432];
char k[128];

int c(const char* str) {
    int ans = str[0];
    for (int i = 1; str[i] != '\0'; ++i) {
        ans <<= 2;
        ans += k[str[i]];
    }
    return ans;
}

int main() {
    k['A'] = 0;
    k['C'] = 1;
    k['G'] = 2;
    k['T'] = 3;
    int n;
    cin >> n;
    char s[7], str[12];
    while (n--) {
        cin >> s >> str;
        if (s[0] == 'i')
            d[c(str)] = true;
        else
            cout << (d[c(str)] ? "yes\n" : "no\n");
    }
    return 0;
}