#include <iostream>
#include <vector>
using namespace std;

int payment(const vector<int>& p) {
    return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}

void charge(int m, vector<int>& ans) {
    ans[3] = m / 500;
    m %= 500;
    ans[2] = m / 100;
    m %= 100;
    ans[1] = m / 50;
    m %= 50;
    ans[0] = m / 10;
}

void _minus(vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < 4; i++) {
        a[i] -= b[i];
    }
}

void _plus(vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < 4; i++) {
        a[i] += b[i];
    }
}

bool judge(const vector<int>& f, const vector<int>& ch) {
    for (int i = 0; i < 4; i++) {
        if (f[i] == 1 && ch[i] > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    
    while (N != 0) {
        vector<int> c(4);
        int sum = 0;
        
        for (int i = 0; i < 4; i++) {
            cin >> c[i];
            sum += c[i];
        }
        
        vector<int> f(4, 0);
        vector<int> pay(4);
        vector<int> ans(4);
        int mini = INT_MAX;
        
        for (pay[0] = 0; pay[0] <= c[0]; pay[0]++) {
            if (pay[0] > 0) {
                f[0] = 1;
            }
            
            for (pay[1] = 0; pay[1] <= c[1]; pay[1]++) {
                if (pay[1] > 0) {
                    f[1] = 1;
                }
                
                for (pay[2] = 0; pay[2] <= c[2]; pay[2]++) {
                    if (pay[2] > 0) {
                        f[2] = 1;
                    }
                    
                    for (pay[3] = 0; pay[3] <= c[3]; pay[3]++) {
                        if (pay[3] > 0) {
                            f[3] = 1;
                        }
                        
                        int m_pay = payment(pay);
                        int n_pay = sum - accumulate(pay.begin(), pay.end(), 0);
                        
                        if (m_pay >= N) {
                            vector<int> ch(4);
                            charge(m_pay - N, ch);
                            int n_charge = accumulate(ch.begin(), ch.end(), 0);
                            
                            if (mini > n_pay + n_charge && judge(f, ch)) {
                                ans = pay;
                                mini = n_pay + n_charge;
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
                if (i == 0) {
                    cout << 10 << " " << ans[i] << endl;
                } else if (i == 1) {
                    cout << 50 << " " << ans[i] << endl;
                } else if (i == 2) {
                    cout << 100 << " " << ans[i] << endl;
                } else if (i == 3) {
                    cout << 500 << " " << ans[i] << endl;
                }
            }
        }
        
        cin >> N;
        
        if (N != 0) {
            cout << endl;
        }
    }
    
    return 0;
}