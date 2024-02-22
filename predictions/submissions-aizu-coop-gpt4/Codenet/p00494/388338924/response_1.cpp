#include <cstdio>
using namespace std;

int main() {
    char x[1000005];
    int a = 0, b = 0, c = 0, d = 0, leng = 0, maxi = 0;
    
    // Read input and calculate length
    for (leng = 0; (x[leng] = getchar()) != '\n'; ++leng);
    x[leng] = 0; // Null-terminate the string
    
    while (a < leng) {
        switch(x[a]) {
            case 'J':
                while (x[a] == 'J') {
                    b++;
                    a++;
                }
                while (x[a] == 'O') {
                    c++;
                    a++;
                }
                while (x[a] == 'I') {
                    d++;
                    a++;
                }
                if (b >= c && c <= d) {
                    maxi = max(maxi, c);
                }
                b = 0;
                c = 0;
                d = 0;
                break;
            default:
                a++;
        }
    }
    printf("%d\n", maxi);
    return 0;
}