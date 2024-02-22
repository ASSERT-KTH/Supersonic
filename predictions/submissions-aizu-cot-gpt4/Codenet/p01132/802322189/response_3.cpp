#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int payment(int* p) {
    return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}

void charge(int m, int* ans) {
    ans[3] = m / 500;
    m %= 500;
    ans[2] = m / 100;
    m %= 100;
    ans[1] = m / 50;
    m %= 50;
    ans[0] = m / 10;
}

bool judge(int* f, int* ch) {
    for (int i = 0; i < 4; ++i)
        if (f[i] == 1 and ch[i] > 0)
            return false;
    return true;
}

int main() {
    int N;
    cin >> N;
    while (1) {
        int c[4], sum = 0, f[4] = {0}, mini = 1e+9, pay[4], ans[4];
        for (int i = 0; i < 4; ++i) {
            cin >> c[i];
            sum += c[i];
        }
        for (pay[0] = 0; pay[0] <= c[0]; ++pay[0]) {
            f[0] = pay[0] > 0;
            for (pay[1] = 0; pay[1] <= c[1]; ++pay[1]) {
                f[1] = pay[1] > 0;
                for (pay[2] = 0; pay[2] <= c[2]; ++pay[2]) {
                    f[2] = pay[2] > 0;
                    for (pay[3] = 0; pay[3] <= c[3]; ++pay[3]) {
                        f[3] = pay[3] > 0;
                        int m_pay = payment(pay);
                        if (m_pay >= N) {
                            int ch[4];
                            charge(m_pay - N, ch);
                            int n_pay = pay[0] + pay[1] + pay[2] + pay[3];
                            int n_charge = ch[0] + ch[1] + ch[2] + ch[3];
                            if (mini > sum - n_pay + n_charge && judge(f, ch)) {
                                copy(begin(pay), end(pay), begin(ans));
                                mini = sum - n_pay + n_charge;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            if (ans[i] > 0)
                cout << (i + 1) * 10 * (i + 1) << " " << ans[i] << "\n";
        }
        cin >> N;
        if (!N)
            break;
        cout << "\n";
    }
}