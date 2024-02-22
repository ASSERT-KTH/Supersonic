#include <queue>
#include <iostream>

using namespace std;

priority_queue<int> pq;

int main() {
    int command, key;

    while (true) {
        cin >> command;

        switch (command) {
            case 0: // end
                return 0;

            case 1: // insert
                cin >> key;
                pq.push(key);
                break;

            case 2: // extract
                if (!pq.empty()) {
                    cout << pq.top() << endl;
                    pq.pop();
                }
                break;
        }
    }

    return 0;
}