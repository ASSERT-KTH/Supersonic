#include <unordered_set>
#include <stdio.h>
#include <string.h>
using namespace std;

char bj[8];
unordered_set<int> vis;
struct pt {
    int ztt;
    int lwz;
    int step;
};
int bs, front = 1, back = 1, tt;
pt dl[1 << 16];
int ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

int char_to_int(const char* bj) {
    int result = 0;
    for (int i = 0; i < 8; ++i) {
        result = result * 10 + (bj[i] - '0');
    }
    return result;
}

int find_zero_index(const char* bj) {
    for (int i = 0; i < 8; ++i) {
        if (bj[i] == '0') return i;
    }
    return -1;
}

void bfs() {
    tt = 0;
    front = 1;
    back = 1;
    bs = 0;
    vis.clear();
    int cs = char_to_int(bj);
    vis.insert(cs);
    pt lsss;
    lsss.ztt = cs;
    lsss.lwz = find_zero_index(bj);
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
        char sss[9];
        int tt = ls1.ztt;
        for (int i = 7; i >= 0; --i) {
            sss[i] = tt % 10;
            tt /= 10;
        }
        for (int i = 0; i < 4; ++i) {
            lsjr.lwz = ls1.lwz + kkk[i];
            if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
                continue;
            if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
                char t = sss[lsjr.lwz];
                sss[lsjr.lwz] = sss[ls1.lwz];
                sss[ls1.lwz] = t;
                lsjr.ztt = 0;
                for (int i = 0; i <= 7; ++i) {
                    lsjr.ztt *= 10;
                    lsjr.ztt += sss[i];
                }
                sss[ls1.lwz] = sss[lsjr.lwz];
                sss[lsjr.lwz] = t;
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
    while (1) {
        if (scanf("%c", &bj[0]) == EOF) {
            return 0;
        }
        scanf("%*c");
        for (int i = 1; i <= 6; ++i) {
            scanf("%c%*c", &bj[i]);
        }
        scanf("%c%*[^\n]\n", &bj[7]);
        bfs();
        if (tt) {
            printf("%d\n", bs);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}