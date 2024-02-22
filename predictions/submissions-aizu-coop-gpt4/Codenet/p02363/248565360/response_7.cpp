#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;

#define MAX 100000

struct edge {
    int t, d;
};

vector<vector<edge>> adjList(MAX);
vector<int> d(MAX);

string BellmanFord(int startVertex, int vNum) {
    fill(d.begin(), d.begin() + vNum, __INT_MAX__);
    d[startVertex] = 0;

    for (int i = 0; i < vNum; ++i) {
        bool update = false;
        for (int s = 0; s < vNum; ++s) {
            if (d[s] == __INT_MAX__) continue;
            for (edge& e : adjList[s]) {
                if (d[e.t] > d[s] + e.d) {
                    d[e.t] = d[s] + e.d;
                    update = true;
                    if (i == vNum - 1) {
                        return "NEGATIVE CYCLE\n";
                    }
                }
            }
        }
        if (!update)
            break;
    }

    stringstream ss;
    for (int i = 0; i < vNum; ++i) {
        if (i > 0)
            ss << " ";
        if (d[i] == __INT_MAX__) {
            ss << "INF";
        } else
            ss << d[i];
    }
    ss << "\n";
    return ss.str();
}

int main() {
    int vNum, eNum;
    cin >> vNum >> eNum;
    int s, t, w;
    for (int i = 0; i < eNum; ++i) {
        cin >> s >> t >> w;
        adjList[s].push_back({t, w});
    }

    string ans;
    for (int i = 0; i < vNum; ++i) {
        ans += BellmanFord(i, vNum);
    }
    cout << ans;
}