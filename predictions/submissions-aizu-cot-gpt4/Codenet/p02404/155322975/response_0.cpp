#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int H, W;
    while(1) {
        cin >> H >> W;
        if (H==0 && W==0) break;
        
        string edge_row(W, '#');
        string middle_row = "#" + string(W-2, '.') + "#";
        
        cout << edge_row << '\n';
        for(int i = 2; i < H; i++) {
            cout << middle_row << '\n';
        }
        if (H > 1) {
            cout << edge_row << '\n';
        }
        cout << '\n';
    }
}