#include <cstdio>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> d;
char k[128];

string c(char str[12]) {
    string ans;
    ans += str[0];
    for (int i = 1; str[i] != '\0'; i++) {
        ans += k[str[i]];
    }
    return ans;
}

int main() {
    k['A'] = 'A';
    k['C'] = 'C';
    k['G'] = 'G';
    k['T'] = 'T';
    int n;
    scanf("%d", &n);
    char s[7], str[12];
    while (n--) {
        scanf("%s %s", s, str);
        if (s[0] == 'i')
            d.insert(c(str));
        else
            puts(d.count(c(str)) ? "yes" : "no");
    }
    return 0;
}