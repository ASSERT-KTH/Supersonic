#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct Data {
    string from, to, message;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<pair<string, string>> OK, NOT;
        for (int i = 0; i < N; ++i) {
            string buf, from, to;
            cin >> buf >> from >> to;
            if (buf[0] == 'p')
                OK.push_back({from, to});
            else
                NOT.push_back({from, to});
        }
        reverse(OK.begin(), OK.end());
        reverse(NOT.begin(), NOT.end());
        queue<Data> Q;
        for (int loop = 0; loop < M; ++loop) {
            Data data;
            cin >> data.from >> data.to >> data.message;
            auto ok = find_if(OK.begin(), OK.end(), [&](const pair<string, string>& p) {
                return (p.first == data.from || p.first == "?") && (p.second == data.to || p.second == "?");
            });
            if (ok == OK.end())
                continue;
            auto notOk = find_if(NOT.begin(), NOT.end(), [&](const pair<string, string>& p) {
                return (p.first == data.from || p.first == "?") && (p.second == data.to || p.second == "?");
            });
            if (notOk != NOT.end())
                continue;
            Q.push(data);
        }
        cout << Q.size() << "\n";
        while (!Q.empty()) {
            cout << Q.front().from << " " << Q.front().to << " " << Q.front().message << "\n";
            Q.pop();
        }
    }
    return 0;
}