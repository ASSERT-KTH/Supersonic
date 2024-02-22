#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Info {
    char from[9];
    char to[9];
    int rank;
    bool erased;
};

struct Data {
    char from[9];
    char to[9];
    char message[51];
};

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        vector<Info> OK, NOT;
        for (int i = 0; i < N; i++) {
            char buf[10], from[9], to[9];
            cin >> buf >> from >> to;

            if (buf[0] == 'p') {
                OK.push_back({from, to, i, false});
            } else {
                NOT.push_back({from, to, i, false});
            }
        }

        for (int i = NOT.size() - 1; i >= 0; i--) {
            for (int k = OK.size() - 1; k >= 0; k--) {
                if (NOT[i].rank < OK[k].rank || OK[k].erased)
                    continue;
                if (strcmp(NOT[i].from, OK[k].from) == 0 && strcmp(NOT[i].to, OK[k].to) == 0) {
                    OK[k].erased = true;
                }
            }
        }

        for (int i = OK.size() - 1; i >= 0; i--) {
            for (int k = NOT.size() - 1; k >= 0; k--) {
                if (OK[i].rank < NOT[k].rank || NOT[k].erased)
                    continue;
                if (strcmp(OK[i].from, NOT[k].from) == 0 && strcmp(OK[i].to, NOT[k].to) == 0) {
                    NOT[k].erased = true;
                }
            }
        }

        int numMessages = 0;
        for (int loop = 0; loop < M; loop++) {
            Data data;
            cin >> data.from >> data.to >> data.message;
            bool FLG = false;
            for (const auto &i : OK) {
                if (i.erased)
                    continue;
                if (strncmp(i.from, data.from, strlen(i.from)) == 0 && strncmp(i.to, data.to, strlen(i.to)) == 0) {
                    FLG = true;
                    break;
                }
            }
            if (!FLG)
                continue;
            FLG = true;
            for (const auto &i : NOT) {
                if (i.erased)
                    continue;
                if (strncmp(i.from, data.from, strlen(i.from)) == 0 && strncmp(i.to, data.to, strlen(i.to)) == 0) {
                    FLG = false;
                    break;
                }
            }
            if (FLG) {
                numMessages++;
                cout << data.from << " " << data.to << " " << data.message << "\n";
            }
        }
        cout << numMessages << "\n";
    }
    return 0;
}