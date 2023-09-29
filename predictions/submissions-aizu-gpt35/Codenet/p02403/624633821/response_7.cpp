#include <iostream>
using namespace std;

int main() {
    int a = 0, H, W;
    while (cin >> H >> W) {
        if (H == 0 && W == 0)
            break;
        if (a > 0)
            cout << endl;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << "#";
            }
            cout << endl;
        }
        a++;
    }
    return 0;
}