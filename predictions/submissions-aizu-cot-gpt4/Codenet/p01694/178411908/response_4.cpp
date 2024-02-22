#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        int ans = 0;
        string now, next;
        for (int i = 0; i < n && cin >> next; ++i) {
            if ((now == "lu" && next == "ru") || (now == "ru" && next == "lu") 
                || (now == "ld" && next == "rd") || (now == "rd" && next == "ld"))
                ++ans;
            now = move(next);
        }
        cout << ans << endl;
    }
    return 0;
}