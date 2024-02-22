#include <cstdio>

const int INPUT_STREAM =  std::cin >>;

int main() {
    int n;
    while (INPUT_STREAM n, n) {
        char a, b;
        int d[256] = {0};
        
        while (n--) {
            INPUT_STREAM a >> b;
            d[a] = b - a;
        }
        
        while (n--) {
            INPUT_STREAM a;
            putchar(a + d[a]);
        }
        putchar('\n');
    }
}