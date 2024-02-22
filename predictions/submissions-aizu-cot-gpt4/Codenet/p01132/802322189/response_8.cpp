#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int payment(const vector<int>& p) {
    return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}

vector<int> charge(int m) {
    vector<int> ans(4);
    ans[3] = m / 500;
    m %= 500;
    ans[2] = m / 100;
    m %= 100;
    ans[1] = m / 50;
    m %= 50;
    ans[0] = m / 10;
    return ans;
}

vector<int> _minus(const vector<int>& a, const vector<int>& b) {
    vector<int> ans(4);
    for (int i = 0; i < 4; ++i)
        ans[i] = a[i] - b[i];
    return ans;
}

vector<int> _plus(const vector<int>& a, const vector<int>& b) {
    vector<int> ans(4);
    for (int i = 0; i < 4; ++i)
        ans[i] = a[i] + b[i];
    return ans;
}

bool judge(const vector<int>& f, const vector<int>& ch) {
    for (int i = 0; i < 4; ++i)
        if (f[i] == 1 and ch[i] > 0)
            return false;
    return true;
}

int main() {
    int N;
    cin >> N;
    while (N) {
        vector<int> c(4);
        int sum = 0;
        for (int i = 0; i < 4; ++i) {
            cin >> c[i];
            sum += c[i];
        }
        vector<int> f(4, 0);
        int mini = 1e+9;
        vector<int> pay(4);
        vector<int> ans(4);
        int m_pay = 0, n_pay = 0;
        for (pay[0] = 0; pay[0] <= c[0]; ++pay[0]) {
            if (pay[0] > 0)
                f[0] = 1;
            m_pay += 10;
            ++n_pay;
            for (pay[1] = 0; pay[1] <= c[1]; ++pay[1]) {
                if (pay[1] > 0)
                    f[1] = 1;
                m_pay += 50;
                ++n_pay;
                for (pay[2] = 0; pay[2] <= c[2]; ++pay[2]) {
                    if (pay[2] > 0)
                        f[2] = 1;
                    m_pay += 100;
                    ++n_pay;
                    for (pay[3] = 0; pay[3] <= c[3]; ++pay[3]) {
                        if (pay[3] > 0)
                            f[3] = 1;
                        m_pay += 500;
                        ++n_pay;
                        if (m_pay >= N) {
                            vector<int> ch = charge(m_pay - N);
                            int n_charge = accumulate(ch.begin(), ch.end(), 0);
                            if (mini > sum - n_pay + n_charge) {
                                if (judge(f, ch)) {
                                    ans = pay;
                                    mini = sum - n_pay + n_charge;
                                }
                            }
                        }
                        if (pay[3] > 0) {
                            f[3] = 0;
                            m_pay -= 500;
                            --n_pay;
                        }
                    }
                    if (pay[2] > 0) {
                        f[2] = 0;
                        m_pay -= 100;
                        --n_pay;
                    }
                }
                if (pay[1] > 0) {
                    f[1] = 0;
                    m_pay -= 50;
                    --n_pay;
                }
            }
            if (pay[0] > 0) {
                f[0] = 0;
                m_pay -= 10;
                --n_pay;
            }
        }
        for (int i = 0; i < 4; ++i) {
            if (ans[i] > 0) {
                cout << (i + 1) * 10 * (i + 1) << " " << ans[i] << "\n";
            }
        }
        cin >> N;
        if (!N)
            break;
        cout << "\n";
    }
}