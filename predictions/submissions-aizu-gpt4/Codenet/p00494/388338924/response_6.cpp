#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char x[1000005];
int a = 0, b = 0, c = 0, d = 0, maxi = 0;
int main() {
    scanf("%s", x);
    int leng = strlen(x);
    for (a = 0; a < leng;) {
        if (x[a] != 'J') {
            a++;
        } else {
            while (x[a] == 'J' && a < leng) {
                b++;
                a++;
            }
            while (x[a] == 'O' && a < leng) {
                c++;
                a++;
            }
            while (x[a] == 'I' && a < leng) {
                d++;
                a++;
            }
            if (b >= c && c <= d) {
                maxi = max(maxi, c);
            }
            b = 0;
            c = 0;
            d = 0;
        }
    }
    printf("%d\n", maxi);
    return 0;
}