#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void playGame(int a[2][9], int z, vector<int>& nums, double& winrate1, double& winrate2) {
    int num[2][9];
    num[0][0] = 0;
    num[1][0] = 0;
    if (a[0][0] > a[1][z])
        num[0][0] = (a[0][0] + a[1][z]);
    else
        num[1][0] = (a[0][0] + a[1][z]);
    for (int i = 1; i < 9; i++) {
        num[0][i] = 0;
        num[1][i] = 0;
    }
    for (int i = 1; i < 9; i++) {
        int j = nums[i - 1];
        if (j <= z)
            j--;
        if (a[0][i] > a[1][j])
            num[0][i] = (a[0][i] + a[1][j]);
        else
            num[1][i] = (a[0][i] + a[1][j]);
    }
    int geitu = 0, jacky = 0;
    for (int i = 0; i < 9; i++) {
        geitu += num[0][i];
        jacky += num[1][i];
    }
    if (geitu > jacky)
        winrate1++;
    else if (geitu < jacky)
        winrate2++;
}

void permute(vector<int>& nums, int l, int r, int a[2][9], double& winrate1, double& winrate2) {
    if (l == r) {
        for (int i = 0; i < 9; i++) {
            playGame(a, i, nums, winrate1, winrate2);
        }
    }
    else {
        for (int i = l; i <= r; i++) {
            swap(nums[l], nums[i]);
            permute(nums, l + 1, r, a, winrate1, winrate2);
            swap(nums[l], nums[i]); // backtrack
        }
    }
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
        vector<int> nums(8);
        for (int i = 0; i < 8; i++) {
            nums[i] = i + 1;
        }
        double winrate1 = 0, winrate2 = 0;
        permute(nums, 0, 7, a, winrate1, winrate2);
        double ans = winrate1 / 362880;
        ans *= 100000;
        ans += 0.5;
        ans = int(ans);
        ans /= 100000;
        double ans2 = winrate2 / 362880;
        ans2 *= 100000;
        ans2 += 0.5;
        ans2 = int(ans2);
        ans2 /= 100000;
        cout << ans << " " << ans2 << "\n";
    }
    return 0;
}