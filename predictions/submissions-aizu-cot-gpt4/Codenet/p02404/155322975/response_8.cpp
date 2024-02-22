#include <cstdio>
using namespace std;
int main() {
    int H, W;
    while (1) {
        scanf("%d %d", &H, &W);
        if (H == 0 && W == 0)
            break;
        string line(W, '#');
        string innerLine = '#' + string(W - 2, '.') + '#';
        for (int i = 1; i <= H; i++) {
            if (i == 1 || i == H) {
                printf("%s\n", line.c_str());
            } else {
                printf("%s\n", innerLine.c_str());
            }
        }
        printf("\n");
    }
}