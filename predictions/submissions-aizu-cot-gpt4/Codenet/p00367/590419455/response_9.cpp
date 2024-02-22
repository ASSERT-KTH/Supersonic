#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Event {
    int time, type;
    bool operator<(const Event& rhs) const {
        if (time != rhs.time) return time < rhs.time;
        return type > rhs.type; // start event has higher priority
    }
};

int calc(int hour, int minute) { return 60 * hour + minute; }

int main() {
    int N;
    scanf("%d", &N);
    vector<Event> events;
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h, &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m, &d_ed_h, &d_ed_m);
        events.push_back({calc(m_st_h, m_st_m), 1});
        events.push_back({calc(m_ed_h, m_ed_m), -1});
        events.push_back({calc(l_st_h, l_st_m), 1});
        events.push_back({calc(l_ed_h, l_ed_m), -1});
        events.push_back({calc(d_st_h, d_st_m), 1});
        events.push_back({calc(d_ed_h, d_ed_m), -1});
    }
    sort(events.begin(), events.end());
    int ans = 0, cnt = 0;
    for (const auto& e : events) {
        cnt += e.type;
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}