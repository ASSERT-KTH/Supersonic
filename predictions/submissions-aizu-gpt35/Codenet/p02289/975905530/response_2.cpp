#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int pop_and_print(priority_queue<int>& qu) {
    if (qu.empty()) {
        return 0;
    }
    cout << qu.top() << endl;
    qu.pop();
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int inp;
    priority_queue<int> qu;
    while (cin >> s) {
        if (s == "end") {
            break;
        }
        if (s == "insert") {
            cin >> inp;
            qu.push(inp);
        } else if (s == "extract") {
            pop_and_print(qu);
        }
    }
    return 0;
}