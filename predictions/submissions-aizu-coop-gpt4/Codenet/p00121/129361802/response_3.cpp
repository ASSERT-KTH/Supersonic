#include <unordered_set>
#include <vector>

struct pt {
    vector<int> ztt;
    int lwz;
    int step;
};

unordered_set<vector<int>> vis;

void bfs() {
    tt = 0;
    front = 1;
    back = 1;
    bs = 0;
    vis.clear();
    vector<int> cs(bj, bj + 8);
    vis.insert(cs);
    pt lsss;
    lsss.ztt = cs;
    lsss.lwz = find(cs.begin(), cs.end(), '0') - cs.begin();
    lsss.step = 0;
    dl[back] = lsss;
    back++;
    while (front < back) {
        pt ls1 = dl[front];
        front++;
        if (ls1.ztt == vector<int>{1, 2, 3, 4, 5, 6, 7, 0}) {
            bs = ls1.step;
            tt = 1;
            return;
        }
        pt lsjr;
        int kkk[4] = {-1, 1, -4, 4};
        for (register int i = 0; i < 4; i++) {
            lsjr.lwz = ls1.lwz + kkk[i];
            if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
                continue;
            if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
                swap(ls1.ztt[lsjr.lwz], ls1.ztt[ls1.lwz]);
                lsjr.ztt = ls1.ztt;
                if (vis.find(lsjr.ztt) == vis.end()) {
                    lsjr.step = ls1.step + 1;
                    vis.insert(lsjr.ztt);
                    dl[back] = lsjr;
                    back++;
                }
                swap(ls1.ztt[lsjr.lwz], ls1.ztt[ls1.lwz]);
            }
        }
    }
}