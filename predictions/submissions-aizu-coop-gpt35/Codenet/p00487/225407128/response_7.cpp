#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    long long a;
    long long b;
    int index;

    Element(long long a = 0, long long b = 0, int index = 0) : a(a), b(b), index(index) {}
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Element> elements(n);

    for (int i = 0; i < n; i++) {
        cin >> elements[i].a >> elements[i].b;
        elements[i].index = i;
    }

    sort(elements.begin(), elements.end(), [](const Element& x, const Element& y) {
        return x.a < y.a;
    });

    int ans = 0;
    long long sum = 0;
    int num = 0;

    vector<bool> use(n, false);

    for (int i = n - 1; i >= 0; i--) {
        sum += elements[i].a;
        use[elements[i].index] = true;
        num++;

        while (i > 0 && elements[i].b == elements[i - 1].b) {
            i--;
            if (!use[elements[i].index]) {
                sum += elements[i].a;
                use[elements[i].index] = true;
                num++;
            }
        }

        if (sum <= num * elements[i].b) {
            ans = max(ans, num);
        }
        sum -= elements[i].a;
        num--;
    }

    cout << ans << endl;

    return 0;
}