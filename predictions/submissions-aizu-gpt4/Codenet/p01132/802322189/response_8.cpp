#include <iostream>
#include <vector>
#include <numeric>

constexpr int denominations[4] = {10, 50, 100, 500};

std::vector<int> charge(int m) {
    std::vector<int> ans(4);
    for(int i=3; i>=0; --i) {
        ans[i] = m / denominations[i];
        m %= denominations[i];
    }
    return ans;
}

bool judge(const std::vector<int>& f, const std::vector<int>& ch) {
    for (int i = 0; i < 4; i++) {
        if (f[i] == 1 && ch[i] > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    while(std::cin >> N && N) {
        std::vector<int> c(4);
        int sum = std::accumulate(c.begin(), c.end(), 0);
        std::vector<int> f(4, 0);
        int mini = INT_MAX;
        std::vector<int> pay(4);
        std::vector<int> ans(4);
        for (pay[0] = 0; pay[0] <= c[0]; pay[0]++) {
            f[0] = pay[0] > 0;
            for (pay[1] = 0; pay[1] <= c[1]; pay[1]++) {
                f[1] = pay[1] > 0;
                for (pay[2] = 0; pay[2] <= c[2]; pay[2]++) {
                    f[2] = pay[2] > 0;
                    for (pay[3] = 0; pay[3] <= c[3]; pay[3]++) {
                        f[3] = pay[3] > 0;
                        int m_pay = std::inner_product(pay.begin(), pay.end(), denominations, 0);
                        if (m_pay >= N) {
                            std::vector<int> ch = charge(m_pay - N);
                            int n_charge = std::accumulate(ch.begin(), ch.end(), 0);
                            if (mini > sum - m_pay + n_charge) {
                                if (judge(f, ch)) {
                                    ans = pay;
                                    mini = sum - m_pay + n_charge;
                                }
                            }
                        }
                        f[3] = 0;
                    }
                    f[2] = 0;
                }
                f[1] = 0;
            }
            f[0] = 0;
        }
        for (int i = 0; i < 4; i++) {
            if (ans[i] > 0) {
                std::cout << denominations[i] << " " << ans[i] << '\n';
            }
        }
    }
}