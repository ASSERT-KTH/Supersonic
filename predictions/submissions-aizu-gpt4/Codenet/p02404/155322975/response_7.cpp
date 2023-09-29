#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W;
    while (1) {
        cin >> H >> W;
        if (H == 0 && W == 0)
            break;
        string border(W, '#');
        string middle = "#" + string(W-2, '.') + "#";
        cout << border << "\n";
        for (int i = 2; i < H; i++) {
            cout << middle << "\n";
        }
        if (H > 1)
            cout << border << "\n";
        cout << "\n";
    }
}