#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const vector<int> denominations = {10, 50, 100, 500};

int payment(const vector<int>& p) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += denominations[i] * p[i];
    }
    return sum;
}

vector<int> charge(int m) {
    vector<int> ans(4);
    for (int i = 3; i >= 0; i--) {
        ans[i] = m / denominations[i];
        m %= denominations[i];
    }
    return ans;
}

bool judge(const vector<int>& f, const vector<int>& ch) {
    for (int i = 0; i < 4; i++)
        if (f[i] == 1 && ch[i] > 0)
            return false;
    return true;
}

int main() {
    int N;
    while (cin >> N && N) {
        vector<int> c(4);
        int sum = 0;
        for (int& ci : c) {
            cin >> ci;
            sum += ci;
        }
        vector<int> f(4, 0);
        int mini = 1e+9;
        vector<int> ans(4);
        for (int pay0 = 0; pay0 <= c[0]; pay0++) {
            f[0] = pay0 > 0 ? 1 : 0;
            for (int pay1 = 0; pay1 <= c[1]; pay1++) {
                f[1] = pay1 > 0 ? 1 : 0;
                for (int pay2 = 0; pay2 <= c[2]; pay2++) {
                    f[2] = pay2 > 0 ? 1 : 0;
                    for (int pay3 = 0; pay3 <= c[3]; pay3++) {
                        f[3] = pay3 > 0 ? 1 : 0;
                        vector<int> pay = {pay0, pay1, pay2, pay3};
                        int m_pay = payment(pay);
                        int n_pay = accumulate(pay.begin(), pay.end(), 0);
                        if (m_pay >= N) {
                            vector<int> ch = charge(m_pay - N);
                            int n_charge = accumulate(ch.begin(), ch.end(), 0);
                            if (mini > sum - n_pay + n_charge && judge(f, ch)) {
                                ans = pay;
                                mini = sum - n_pay + n_charge;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            if (ans[i] > 0) {
                cout << denominations[i] << " " << ans[i] << "\n";
            }
        }
        cout << "\n";
    }
}