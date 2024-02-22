#include <cstdlib>
#include <iostream>
using namespace std;

double calculateWinRate(int a[2][9], int moves[9], int moveIndex, int num0, int num1, double winrate1, double winrate2) {
    if (moveIndex == 9) {
        if (num0 > num1)
            winrate1++;
        else if (num0 < num1)
            winrate2++;
    } else {
        for (int i = 0; i < 9; i++) {
            bool alreadyUsed = false;
            for (int j = 0; j < moveIndex; j++) {
                if (moves[j] == i) {
                    alreadyUsed = true;
                    break;
                }
            }
            if (!alreadyUsed) {
                int num0Updated = num0;
                int num1Updated = num1;
                if (a[0][moveIndex] > a[1][i])
                    num0Updated += a[0][moveIndex] + a[1][i];
                else
                    num1Updated += a[0][moveIndex] + a[1][i];
                calculateWinRate(a, moves, moveIndex + 1, num0Updated, num1Updated, winrate1, winrate2);
            }
        }
    }
    return winrate1 / 362880;
}

int main() {
    int n;
    cin >> n;
    for (int l = 0; l < n; l++) {
        int a[2][9];
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 9; k++)
                cin >> a[j][k];
        }
        int moves[9] = {0};
        double winrate1 = 0, winrate2 = 0;
        double ans, ans2;
        ans = calculateWinRate(a, moves, 0, 0, 0, winrate1, winrate2);
        ans *= 100000;
        ans += 0.5;
        ans = int(ans);
        ans /= 100000;
        ans2 = 1 - ans;
        cout << ans << " " << ans2 << "\n";
    }
    return 0;
}