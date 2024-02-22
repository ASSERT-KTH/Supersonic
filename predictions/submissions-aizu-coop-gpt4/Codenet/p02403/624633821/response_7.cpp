#include <cstdio>
#include <string>
using namespace std;

int main() {
    int a = 0, H[100], W[100];

    // Use scanf consistently for input
    while (scanf("%d %d", &H[a], &W[a]), H[a] || W[a]) {
        a++;
    }

    for (int b = 0; b < a; b++) {
        // Create a string filled with '#' characters and print it
        string line(W[b], '#');
        for (int i = 0; i < H[b]; i++) {
            printf("%s\n", line.c_str());
        }

        printf("\n");
    }

    return 0;
}