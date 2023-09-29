#include <cstdio>
#include <unordered_map>
using namespace std;
bool d[1 << 25];
unordered_map<string, int> k;
int c(char str[12]) {
    int ans = k[string(str, str + 10)];
    return ans;
}
int main() {
    k["A"] = 0;
    k["C"] = 1;
    k["G"] = 2;
    k["T"] = 3;
    int n;
    scanf("%d", &n);
    char s[7], str[12];
    while (n--) {
        scanf("%s %s", s, str);
        if (s[0] == 'i')
            d[c(str)] = true;
        else
            puts(d[c(str)] ? "yes" : "no");
    }
    return 0;
}