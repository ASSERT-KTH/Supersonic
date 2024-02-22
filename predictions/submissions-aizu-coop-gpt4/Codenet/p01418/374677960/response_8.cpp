#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct State {
    int d;
    double l;
    double r;
    double mid;
};

int K, R, L;
double P, E, T;

int main() {
    cin >> K >> L >> R >> P >> E >> T;
    
    stack<State> s;
    s.push({K, L, R});
    
    double result = 0.0;
    
    while (!s.empty()) {
        State curr = s.top();
        s.pop();
        
        double mid = (curr.l + curr.r) / 2;
        
        if (!curr.d) {
            result += (T - E < mid && mid < T + E) ? 1 : 0;
            continue;
        }
        
        if (curr.r < T - E || T + E < curr.l)
            continue;
        
        if (mid >= T) {
            s.push({curr.d - 1, curr.l, mid});
            s.push({curr.d - 1, mid, curr.r});
            result += (1.0 - P) * mid + P * mid;
        } else {
            s.push({curr.d - 1, mid, curr.r});
            s.push({curr.d - 1, curr.l, mid});
            result += (1.0 - P) * mid + P * mid;
        }
    }
    
    printf("%.9f\n", result);
    
    return 0;
}