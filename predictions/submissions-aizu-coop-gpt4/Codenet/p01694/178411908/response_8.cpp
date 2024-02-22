#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    do {
        scanf("%d", &n);
        if (n == 0) break;
        int ans = 0;
        string now = "", next;
        for (int i = 0; i < n; ++i) {
            cin >> next;
            if (now == "lu" && next == "ru")
                ans++;
            else if (now == "ru" && next == "lu")
                ans++;
            else if (now == "ld" && next == "rd")
                ans++;
            else if (now == "rd" && next == "ld")
                ans++;
            now = next;
        }
        printf("%d\n", ans);
    } while (true);
    return 0;
}