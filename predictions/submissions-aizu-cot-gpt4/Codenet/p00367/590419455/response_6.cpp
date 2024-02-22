#include <algorithm>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <time.h>
#include <vector>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

struct Info {
    int morning_start, morning_end, lunch_start, lunch_end, dinner_start, dinner_end;
};

struct TimeInterval {
    int time;
    int period; // 0 for morning, 1 for lunch, 2 for dinner
};

int calc(int hour, int minute) { return 60 * hour + minute; }

bool compareTimeInterval(TimeInterval a, TimeInterval b) { return a.time < b.time; }

int main() {
    int N;
    scanf("%d", &N);
    Info info[N];
    vector<TimeInterval> timeIntervals;
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h, &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m, &d_ed_h, &d_ed_m);
        info[i].morning_start = calc(m_st_h, m_st_m);
        info[i].morning_end = calc(m_ed_h, m_ed_m);
        info[i].lunch_start = calc(l_st_h, l_st_m);
        info[i].lunch_end = calc(l_ed_h, l_ed_m);
        info[i].dinner_start = calc(d_st_h, d_st_m);
        info[i].dinner_end = calc(d_ed_h, d_ed_m);
        timeIntervals.push_back({info[i].morning_start, 0});
        timeIntervals.push_back({info[i].morning_end, 0});
        timeIntervals.push_back({info[i].lunch_start, 1});
        timeIntervals.push_back({info[i].lunch_end, 1});
        timeIntervals.push_back({info[i].dinner_start, 2});
        timeIntervals.push_back({info[i].dinner_end, 2});
    }
    sort(timeIntervals.begin(), timeIntervals.end(), compareTimeInterval);
    int ans = 0, tmp;
    for (int a = 0; a < timeIntervals.size(); a++) {
        tmp = 0;
        for (int i = 0; i < N; i++) {
            if (info[i].morning_start <= timeIntervals[a].time && info[i].morning_end >= timeIntervals[a].time) tmp++;
            else if (info[i].lunch_start <= timeIntervals[a].time && info[i].lunch_end >= timeIntervals[a].time) tmp++;
            else if (info[i].dinner_start <= timeIntervals[a].time && info[i].dinner_end >= timeIntervals[a].time) tmp++;
        }
        if (tmp > ans) ans = tmp;
    }
    printf("%d\n", ans);
    return 0;
}