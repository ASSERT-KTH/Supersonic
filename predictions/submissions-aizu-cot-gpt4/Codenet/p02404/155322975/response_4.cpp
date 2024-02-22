#include <cstdio>
#include <string>
using namespace std;
int main() {
    int H, W;
    while (1) {
        scanf("%d %d", &H, &W);
        if (H == 0 && W == 0)
            break;

        // print first row
        printf("%s\n", string(W, '#').c_str());

        // print middle rows
        string middleRow = "#" + string(W-2, '.') + "#";
        for (int i = 2; i < H; i++) {
            printf("%s\n", middleRow.c_str());
        }

        // print last row
        if (H > 1) {
            printf("%s\n", string(W, '#').c_str());
        }
        printf("\n");
    }
    return 0;
}