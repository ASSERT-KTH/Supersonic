#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Info {
    int mornint_start, morning_end, lunch_start, lunch_end, dinner_start,
        dinner_end;
};

int calc(int hour, int minute) { return 60 * hour + minute; }

int main() {
    int N;
    scanf("%d", &N);
    Info info[N];
    multiset<int> MORNING, LUNCH, DINNER;
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h,
        d_st_m, d_ed_h, d_ed_m;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h,
              &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m,
              &d_ed_h, &d_ed_m);
        info[i].mornint_start = calc(m_st_h, m_st_m);
        info[i].morning_end = calc(m_ed_h, m_ed_m);
        MORNING.insert(info[i].mornint_start);
        MORNING.insert(info[i].morning_end);
        info[i].lunch_start = calc(l_st_h, l_st_m);
        info[i].lunch_end = calc(l_ed_h, l_ed_m);
        LUNCH.insert(info[i].lunch_start);
        LUNCH.insert(info[i].lunch_end);
        info[i].dinner_start = calc(d_st_h, d_st_m);
        info[i].dinner_end = calc(d_ed_h, d_ed_m);
        DINNER.insert(info[i].dinner_start);
        DINNER.insert(info[i].dinner_end);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int tmp = distance(MORNING.lower_bound(info[i].mornint_start), MORNING.upper_bound(info[i].morning_end)) * 
                  distance(LUNCH.lower_bound(info[i].lunch_start), LUNCH.upper_bound(info[i].lunch_end)) * 
                  distance(DINNER.lower_bound(info[i].dinner_start), DINNER.upper_bound(info[i].dinner_end));
        ans = max(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}