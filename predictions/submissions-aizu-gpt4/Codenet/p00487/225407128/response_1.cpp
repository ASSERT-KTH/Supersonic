#include <algorithm>
#include <iostream>
#include <vector>
#define fs first
#define sc second
using namespace std;
using ll = long long;

struct Data {
    ll a, b;
    int idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<Data> data(n);
    vector<bool> use(n, false);
    for (int i = 0; i < n; i++) {
        cin >> data[i].a >> data[i].b;
        data[i].idx = i;
    }

    sort(data.begin(), data.end(), [](const Data& x, const Data& y){
        return x.b < y.b || (x.b == y.b && x.a < y.a);
    });

    int ans = 0;
    ll sum = 0;
    int num = 0;
    int id = 0;
    for (int i = 0; i < n; i++) {
        if (!use[data[i].idx]) {
            sum += data[i].a;
            use[data[i].idx] = true;
            num++;
        }
        while (id < n && data[id].a <= data[i].b) {
            if (!use[data[id].idx]) {
                sum += data[id].a;
                use[data[id].idx] = true;
                num++;
            }
            id++;
        }
        while (id < n && sum + data[id].a <= (num + 1) * data[i].b) {
            if (!use[data[id].idx]) {
                sum += data[id].a;
                use[data[id].idx] = true;
                num++;
            }
            id++;
        }
        if (sum <= num * data[i].b)
            ans = max(ans, num);
        sum -= data[i].a;
        num--;
    }
    cout << ans << "\n";
}