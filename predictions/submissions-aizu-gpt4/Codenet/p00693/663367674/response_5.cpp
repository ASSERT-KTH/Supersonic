#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>

struct Info {
    std::string from, to;
    int rank;
    bool erased;
};

struct Data {
    std::string from, to, message;
};

bool ambiguousCmp(const std::string& base, const std::string& comp) {
    return std::equal(base.begin(), base.end(), comp.begin(), comp.end(), [](char a, char b) {
        return a == '?' || a == b;
    });
}

void func() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<Info> OK(N), NOT(N);

    std::string buf, from, to;
    int ok_index = 0, not_index = 0;

    for (int i = 0; i < N; i++) {
        std::cin >> buf >> from >> to;
        if (buf[0] == 'p') {
            OK[ok_index] = {from, to, i, false};
            ++ok_index;
        } else {
            NOT[not_index] = {from, to, i, false};
            ++not_index;
        }
    }
    for (int i = not_index - 1; i >= 0; i--) {
        for (int k = ok_index - 1; k >= 0; k--) {
            if (NOT[i].rank < OK[k].rank || OK[k].erased)
                continue;
            if (NOT[i].from == OK[k].from && NOT[i].to == OK[k].to)
                OK[k].erased = true;
        }
    }
    for (int i = ok_index - 1; i >= 0; i--) {
        for (int k = not_index - 1; k >= 0; k--) {
            if (OK[i].rank < NOT[k].rank || NOT[k].erased)
                continue;
            if (OK[i].from == NOT[k].from && OK[i].to == NOT[k].to)
                NOT[k].erased = true;
        }
    }
    std::queue<Data> Q;
    for (int loop = 0; loop < M; loop++) {
        Data data;
        std::cin >> data.from >> data.to >> data.message;
        bool FLG = false;
        for (int i = 0; i < ok_index; i++) {
            if (OK[i].erased)
                continue;
            if (ambiguousCmp(OK[i].from, data.from) && ambiguousCmp(OK[i].to, data.to)) {
                FLG = true;
                break;
            }
        }
        if (!FLG)
            continue;
        FLG = true;
        for (int i = 0; i < not_index; i++) {
            if (NOT[i].erased)
                continue;
            if (ambiguousCmp(NOT[i].from, data.from) && ambiguousCmp(NOT[i].to, data.to)) {
                FLG = false;
                break;
            }
        }
        if (FLG) {
            Q.push(data);
        }
    }
    std::cout << Q.size() << "\n";
    while (!Q.empty()) {
        std::cout << Q.front().from << " " << Q.front().to << " " << Q.front().message << "\n";
        Q.pop();
    }
}

int main() {
    int N, M;
    while (std::cin >> N >> M, N || M)
        func();
    return 0;
}