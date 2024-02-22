#include <iostream>
#include <string>
using namespace std;

int main() {
    int H, W;
    while (1) {
        cin >> H >> W;
        if (H == 0 && W == 0)
            break;
        string border(W, '#');
        string middle = "#" + string(W-2, '.') + "#";

        // Print top border
        cout << border << endl;

        // Print middle rows
        for (int i = 2; i < H; i++) {
            cout << middle << endl;
        }

        // Print bottom border
        if (H!=1) cout << border << endl;

        cout << endl;
    }
}