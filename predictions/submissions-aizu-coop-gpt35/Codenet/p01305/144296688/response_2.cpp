#include <cstdlib>
#include <iostream>
using namespace std;

// Recursive function to generate all possible combinations of moves
void generateCombinations(int depth, int* a, int* num, double& winrate1, double& winrate2) {
    if (depth == 9) {
        int geitu = 0;
        int jacky = 0;
        for (int m = 0; m < 9; m++) {
            geitu += num[m];
            jacky += a[m];
        }
        if (geitu > jacky)
            winrate1++;
        else if (geitu < jacky)
            winrate2++;
        return;
    }

    for (int i = 0; i < 9; i++) {
        if (a[depth] > num[i])
            num[depth] = a[depth] + num[i];
        else
            num[depth] = num[depth];
        generateCombinations(depth + 1, a, num, winrate1, winrate2);
    }
}

int main() {
    int n;
    cin >> n;

    for (int l = 0; l < n; l++) {
        int a[9], num[9];
        double winrate1 = 0, winrate2 = 0;

        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 9; k++)
                cin >> a[k];
        }

        generateCombinations(0, a, num, winrate1, winrate2);

        double ans1 = winrate1 / 362880;
        double ans2 = winrate2 / 362880;

        cout << fixed << ans1 << " " << ans2 << "\n";
    }

    return 0;
}