#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    while (cin >> H >> W && H && W) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout.put((i ^ j) & 1 ? '#' : '.');
            }
            cout.put('\n');
        }
        cout.put('\n');
    }
    
    return 0;
}