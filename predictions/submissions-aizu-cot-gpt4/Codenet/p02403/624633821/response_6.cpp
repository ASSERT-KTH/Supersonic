#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int h, w;
    while (1) {
        cin >> h >> w;
        if (h == 0 && w == 0)
            break;

        string row(w, '#');
        for (int i = 0; i < h; i++) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}