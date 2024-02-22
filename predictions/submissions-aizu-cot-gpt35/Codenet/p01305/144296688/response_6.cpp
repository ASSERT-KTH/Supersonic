#include <iostream>
#include <vector>
using namespace std;

double calculateWinRate(vector<vector<int>>& a, vector<int>& num, int idx) {
    if (idx == 9) {
        int geitu = 0, jacky = 0;
        for (int m = 0; m < 9; m++) {
            geitu += num[m];
            jacky += a[1][m] - num[m];
        }
        if (geitu > jacky)
            return 1.0;
        else if (geitu < jacky)
            return 0.0;
        else
            return 0.5;
    }
    
    double winrate = 0.0;
    for (int i = 0; i < 9; i++) {
        if (num[i] == -1) {
            num[i] = a[0][idx];
            winrate += calculateWinRate(a, num, idx + 1);
            num[i] = -1;
        }
    }
    return winrate;
}

int main() {
    int n;
    cin >> n;
    
    for (int l = 0; l < n; l++) {
        vector<vector<int>> a(2, vector<int>(9));
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 9; k++)
                cin >> a[j][k];
        }
        
        vector<int> num(9, -1);
        double winrate1 = calculateWinRate(a, num, 0);
        double winrate2 = 1.0 - winrate1;
        
        cout << fixed;
        cout.precision(5);
        cout << winrate1 << " " << winrate2 << "\n";
    }
    
    return 0;
}