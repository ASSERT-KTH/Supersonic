#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int key;
    string com;
    while (cin >> com) {
        if (com[0] == 'e' && com[1] == 'n')
            break;
        if (com[0] == 'i') {
            cin >> key;
            pq.push(key);
        } else {
            cout << pq.top() << "\n";
            pq.pop();
        }
    }

    return 0;
}