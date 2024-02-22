#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <queue>

using namespace std;

// Define a custom comparator for the priority queue
struct DataComparator {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.second < p2.second || (p1.second == p2.second && p1.first > p2.first);
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Use a map to store the scores instead of an array
    map<int, int> S;

    // Use a priority queue with the custom comparator
    priority_queue<pair<int, int>, vector<pair<int, int>>, DataComparator> Q;

    Q.push(make_pair(0, 0));

    pair<int, int> maxData = make_pair(0, 0); // Track the data with the maximum score

    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        S[a] += b;
        Q.push(make_pair(a, S[a]));

        // Update the maxData if the new score is higher
        if (S[a] > maxData.second || (S[a] == maxData.second && a < maxData.first)) {
            maxData = make_pair(a, S[a]);
        }

        // Print the maxData
        cout << maxData.first << " " << maxData.second << endl;
    }

    return 0;
}