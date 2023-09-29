#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Person {
    ll position;
    int direction;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    ll T;
    cin >> N >> T >> Q;
    vector<Person> people(N);
    vector<int> queries(Q);
    for (int i = 0; i < N; i++) {
        cin >> people[i].position >> people[i].direction;
    }
    for (int i = 0; i < Q; i++) {
        cin >> queries[i];
        queries[i]--;
    }

    ll target = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (i == N - 1 || (people[i].direction == 1 && people[i+1].direction == 2)) {
            target = people[i].position + T;
        }
        if (people[i].direction == 2) {
            target = min(target, people[i].position - T);
        }
        people[i].position = target;
    }

    target = 1e18;
    for (int i = 0; i < N; i++) {
        if (i == 0 || (people[i].direction == 2 && people[i-1].direction == 1)) {
            target = people[i].position - T;
        }
        if (people[i].direction == 1) {
            target = max(target, people[i].position + T);
        }
        people[i].position = min(people[i].position, target);
    }

    for (int i = 0; i < Q; i++) {
        cout << people[queries[i]].position << "\n";
    }
    return 0;
}