#include <cstdio>
#include <cstring>
using namespace std;
char x[1000005];
int a = 0, b = 0, c = 0, d = 0, maxi = 0;
int main() {
    scanf("%s", x);
    int leng = strlen(x);
    for (int i = 0; i < leng; i++) {
        if (x[i] == 'J') {
            b++;
        } else if (x[i] == 'O') {
            c++;
        } else if (x[i] == 'I') {
            d++;
        }
        if (b >= c && c <= d) {
            maxi = max(maxi, c);
        }
    }
    printf("%d\n", maxi);
    scanf("%d", &a);
    return 0;
}