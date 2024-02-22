#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int zzzt[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int bj[8];
unordered_set<int> vis;
struct pt {
    int ztt;
    int lwz;
    int step;
};
int bs, front = 1, back = 1, tt;
pt dl[1 << 16];
int ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
void bfs() {
    tt = bs = 0;
    front = back = 1;
    vis.clear();
    int cs = 0;
    for(int i = 0; i < 8; ++i) cs = cs * 10 + bj[i];
    vis.insert(cs);
    pt lsss;
    lsss.ztt = cs;
    lsss.lwz = find(bj, bj + 8, 0) - bj;
    lsss.step = 0;
    dl[back++] = lsss;
    while (front < back) {
        pt ls1 = dl[front++];
        if (ls1.ztt == 1234567) {
            bs = ls1.step;
            tt = 1;
            return;
        }
        pt lsjr;
        int kkk[4] = {-1, 1, -4, 4};
        int sss[9];
        int tt = ls1.ztt;
        for (register int i = 7; i >= 0; --i) {
            sss[i] = tt % 10;
            tt /= 10;
        }
        for (register int i = 0; i < 4; ++i) {
            lsjr.lwz = ls1.lwz + kkk[i];
            if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
                continue;
            if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
                swap(sss[lsjr.lwz], sss[ls1.lwz]);
                lsjr.ztt = 0;
                for (register int i = 0; i <= 7; ++i) {
                    lsjr.ztt *= 10;
                    lsjr.ztt += sss[i];
                }
                swap(sss[lsjr.lwz], sss[ls1.lwz]);
                if (!vis.count(lsjr.ztt)) {
                    lsjr.step = ls1.step + 1;
                    vis.insert(lsjr.ztt);
                    dl[back++] = lsjr;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        for(int i = 0; i < 8; ++i) {
            if(!(cin >> bj[i])) return 0;
        }
        bfs();
        if (tt) cout << bs << "\n";
        else cout << "-1\n";
    }
    return 0;
}