#include <cstdio>
using namespace std;

char x[1000005];
int a = 0, b = 0, c = 0, d = 0, maxi = 0;

int get_sequence_length(char target){
    int length = 0;
    while (x[a] == target) {
        length++;
        a++;
    }
    return length;
}

int main() {
    a = 0;
    scanf("%s%n", x, &a);
    while (a--) {
        if (x[a] != 'J') {
            a++;
        } else {
            b = get_sequence_length('J');
            c = get_sequence_length('O');
            d = get_sequence_length('I');
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