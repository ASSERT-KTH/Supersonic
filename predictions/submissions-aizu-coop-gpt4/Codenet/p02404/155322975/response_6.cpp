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
        string inner = "#" + string(W - 2, '.') + "#";

        cout << border << endl;
        for (int i = 2; i < H; i++)
            cout << inner << endl;
        if (H > 1)
            cout << border << endl;
        
        cout << endl;
    }
}