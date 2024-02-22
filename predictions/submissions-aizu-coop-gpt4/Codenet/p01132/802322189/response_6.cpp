#include <iostream>
#include <vector>
#include <numeric>
#include <cstdio>

using namespace std;

int payment(array<int, 4> &p) {
    return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}

array<int, 4> charge(int m) {
    array<int, 4> ans = {0};
    ans[3] = m / 500;
    m %= 500;
    ans[2] = m / 100;
    m %= 100;
    ans[1] = m / 50;
    m %= 50;
    ans[0] = m / 10;
    return ans;
}

bool judge(array<int, 4> &f, array<int, 4> &ch) {
    for (int i = 0; i < 4; i++)
        if (f[i] == 1 and ch[i] > 0)
            return false;
    return true;
}

int main() {
    int N;
    scanf("%d", &N);

    while (N) {
        array<int, 4> c;
        int sum = 0;

        for (int i = 0; i < 4; i++) {
            scanf("%d", &c[i]);
            sum += c[i];
        }

        array<int, 4> f = {0};
        int mini = 1e+9;
        array<int, 4> pay;
        array<int, 4> ans;

        for (pay[0] = 0; pay[0] <= c[0]; pay[0]++) {
            f[0] = pay[0] > 0;

            for (pay[1] = 0; pay[1] <= c[1]; pay[1]++) {
                f[1] = pay[1] > 0;

                for (pay[2] = 0; pay[2] <= c[2]; pay[2]++) {
                    f[2] = pay[2] > 0;

                    for (pay[3] = 0; pay[3] <= c[3]; pay[3]++) {
                        f[3] = pay[3] > 0;
                        int m_pay = payment(pay);
                        int n_pay = pay[0] + pay[1] + pay[2] + pay[3];

                        if (m_pay >= N) {
                            array<int, 4> ch = charge(m_pay - N);
                            int n_charge = ch[0] + ch[1] + ch[2] + ch[3];

                            if (mini > sum - n_pay + n_charge) {
                                if (judge(f, ch)) {
                                    ans = pay;
                                    mini = sum - n_pay + n_charge;
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            if (ans[i] > 0) {
                printf("%d %d\n", (i + 1) * 10 * (i + 1), ans[i]);
            }
        }

        scanf("%d", &N);
        if (N) printf("\n");
    }
}