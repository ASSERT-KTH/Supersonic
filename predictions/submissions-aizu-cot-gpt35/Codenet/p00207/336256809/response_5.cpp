#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Define a type alias for the maze representation
using Maze = vector<vector<int>>;

void meiro(Maze& C, int W, int H, int c) {
    stack<pair<int, int>> st;
    st.push({W, H});
    
    while (!st.empty()) {
        auto [x, y] = st.top();
        st.pop();
        
        if (C[x][y] != c) {
            continue;
        }
        
        C[x][y] = -1;
        
        // Check neighboring cells
        if (x > 0) st.push({x - 1, y});
        if (y < C[0].size() - 1) st.push({x, y + 1});
        if (x < C.size() - 1) st.push({x + 1, y});
        if (y > 0) st.push({x, y - 1});
    }
}

int main() {
    int w, h;
    cin >> w >> h;
    
    while (w != 0 || h != 0) {
        // Initialize the maze with default value -1
        Maze C(w, vector<int>(h, -1));
        
        int xs, ys, xg, yg;
        cin >> xs >> ys >> xg >> yg;
        
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            int c, d, x, y;
            cin >> c >> d >> x >> y;
            
            // Update the maze cells based on the block orientation
            for (int j = x; j < x + (d == 0 ? 4 : 2); j++) {
                for (int k = y; k < y + (d == 0 ? 2 : 4); k++) {
                    C[j][k] = c;
                }
            }
        }
        
        meiro(C, xs, ys, C[xs][ys]);
        
        if (C[xg][yg] == -1) {
            cout << "OK" << endl;
        } else {
            cout << "NG" << endl;
        }
        
        cin >> w >> h;
    }
    
    return 0;
}