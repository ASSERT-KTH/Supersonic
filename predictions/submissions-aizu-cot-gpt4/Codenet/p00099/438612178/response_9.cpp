#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000001;
int S[MAX];
namespace MySpace {
    struct data {
        int num, score;
        data(int n, int s) : num(n), score(s) {}
        bool operator<(const data &d) const {
            if (score != d.score)
                return score < d.score;
            return num > d.num;
        }
    };
}
int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<MySpace::data> Q;
    Q.push(MySpace::data(0, 0));
    MySpace::data now;
    do {
        int a, b;
        cin >> a >> b;
        S[a] += b;
        Q.push(MySpace::data(a, S[a]));
        now = Q.top();
        if (now.score == S[now.num]) {
            cout << now.num << " " << now.score << endl;
        } else {
            Q.pop();
        }
    } while (now.score != S[now.num]);
    return 0;
}