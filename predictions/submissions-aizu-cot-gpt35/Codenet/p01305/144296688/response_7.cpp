#include <iostream>
using namespace std;

int a[2][9];
int geitu, jacky;
double winrate1, winrate2;

void calculateWinRates(int z, int sumGeitu, int sumJacky, int count) {
    if (count == 9) {
        if (sumGeitu > sumJacky)
            winrate1++;
        else if (sumGeitu < sumJacky)
            winrate2++;
        return;
    }
  
    for (int i = 0; i < 9; i++) {
        if (i == z)
            continue;
      
        int numGeitu = (a[0][count] > a[1][i]) ? a[0][count] + a[1][i] : 0;
        int numJacky = (a[0][count] > a[1][i]) ? 0 : a[0][count] + a[1][i];
      
        calculateWinRates(z, sumGeitu + numGeitu, sumJacky + numJacky, count + 1);
    }
}

int main() {
    int n;
    cin >> n;
  
    while (n--) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 9; k++)
                cin >> a[j][k];
        }
      
        winrate1 = 0;
        winrate2 = 0;
      
        for (int z = 0; z < 9; z++) {
            calculateWinRates(z, 0, 0, 0);
        }
      
        double ans1 = winrate1 / 362880.0 * 100000 + 0.5;
        double ans2 = winrate2 / 362880.0 * 100000 + 0.5;
      
        cout << int(ans1) / 100000.0 << " " << int(ans2) / 100000.0 << "\n";
    }
  
    return 0;
}