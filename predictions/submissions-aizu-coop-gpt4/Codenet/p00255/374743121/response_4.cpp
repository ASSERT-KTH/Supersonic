#include <iostream>
#include <queue>
using namespace std;

int main() {
    long long n, s, a;
    while (cin >> n && n != 0) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        cin >> a;
        s = a;
        for (long long i = 1; i < n; ++i) {
            cin >> a;
            s += a;
            pq.push(a);
        }

        a = n * s;
        while (!pq.empty()) {
            s += pq.top();
            pq.pop();
            a = max(a, n * s);
        }

        cout << a << endl;
    }

    return 0;
}