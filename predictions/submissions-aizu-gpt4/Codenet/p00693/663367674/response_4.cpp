#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Info {
    string from, to;
    int rank;
    bool erased;
};

struct Data {
    string from, to, message;
};

int N, M;
vector<Info> OK, NOT;
queue<Data> Q;

void func() {
    OK.clear(); NOT.clear();
    while (!Q.empty()) Q.pop();

    string buf, from, to;
    for (int i = 0; i < N; ++i) {
        cin >> buf >> from >> to;
        if (buf[0] == 'p') {
            OK.push_back({from, to, i, false});
        } else {
            NOT.push_back({from, to, i, false});
        }
    }

    for (auto &not_info : NOT) {
        for (auto &ok_info : OK) {
            if (not_info.rank < ok_info.rank || ok_info.erased)
                continue;
            if (not_info.from == ok_info.from && not_info.to == ok_info.to) {
                ok_info.erased = true;
            }
        }
    }

    for (auto &ok_info : OK) {
        for (auto &not_info : NOT) {
            if (ok_info.rank < not_info.rank || not_info.erased)
                continue;
            if (ok_info.from == not_info.from && ok_info.to == not_info.to) {
                not_info.erased = true;
            }
        }
    }
    
    Data data;
    for (int loop = 0; loop < M; ++loop) {
        cin >> data.from >> data.to >> data.message;
        bool flag = false;
        for (auto &ok_info : OK) {
            if (ok_info.erased) continue;
            if (ok_info.from == data.from && ok_info.to == data.to) {
                flag = true;
                break;
            }
        }
        if (!flag) continue;
        flag = true;
        for (auto &not_info : NOT) {
            if (not_info.erased) continue;
            if (not_info.from == data.from && not_info.to == data.to) {
                flag = false;
                break;
            }
        }
        if (flag) {
            Q.push(data);
        }
    }

    cout << Q.size() << '\n';
    while (!Q.empty()) {
        cout << Q.front().from << ' ' << Q.front().to << ' ' << Q.front().message << '\n';
        Q.pop();
    }
}

int main() {
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        func();
    }
    return 0;
}