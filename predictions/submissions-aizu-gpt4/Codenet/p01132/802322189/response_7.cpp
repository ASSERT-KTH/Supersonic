#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

constexpr int payment(const int& i) {
    static const int fees[4] = {10, 50, 100, 500};
    return fees[i];
}

vector<int> charge(int m) {
    vector<int> ans(4);
    for(int i = 3; i >= 0; --i) {
        ans[i] = m / payment(i);
        m %= payment(i);
    }
    return ans;
}

bool judge(vector<int>& f, vector<int>& ch) {
    for (int i = 0; i < 4; ++i)
        if (f[i] && ch[i])
            return false;
    return true;
}

int main() {
    int N;
    while(cin >> N && N) {
        vector<int> c(4);
        int sum = 0;
        for (int & i : c) {
            cin >> i;
            sum += i;
        }
        vector<int> ans(4);
        int mini = 1e+9;
        vector<int> pay(4);
        vector<int> f(4);
        for (pay[0] = 0; pay[0] <= c[0]; ++pay[0]) {
            for (pay[1] = 0; pay[1] <= c[1]; ++pay[1]) {
                for (pay[2] = 0; pay[2] <= c[2]; ++pay[2]) {
                    for (pay[3] = 0; pay[3] <= c[3]; ++pay[3]) {
                        int m_pay = 0;
                        int n_pay = 0;
                        for(int i = 0; i < 4; ++i) {
                            m_pay += pay[i] * payment(i);
                            f[i] = pay[i] > 0;
                            n_pay += pay[i];
                        }
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
        static const int bills[4] = {10, 50, 100, 500};
        for (int i = 0; i < 4; ++i) {
            if (ans[i] > 0) {
                cout << bills[i] << " " << ans[i] << endl;
            }
        }
    }
    return 0;
}