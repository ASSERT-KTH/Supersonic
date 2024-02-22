#include <iostream>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
#define MAX_TIME 24*60+1
using namespace std;

struct Info {
  int mornint_start, morning_end, lunch_start, lunch_end, dinner_start, dinner_end;
};

int calc(int hour, int minute) { return 60 * hour + minute; }

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int N;
  cin >> N;
  Info info[N];
  int MORNING[MAX_TIME] = {0}, LUNCH[MAX_TIME] = {0}, DINNER[MAX_TIME] = {0};
  int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
  for (int i = 0; i < N; i++) {
    cin >> m_st_h >> m_st_m >> m_ed_h >> m_ed_m >> l_st_h >> l_st_m >> l_ed_h >> l_ed_m >> d_st_h >> d_st_m >> d_ed_h >> d_ed_m;
    info[i].mornint_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    for(int j=info[i].mornint_start; j<=info[i].morning_end; j++) MORNING[j]++;
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    for(int j=info[i].lunch_start; j<=info[i].lunch_end; j++) LUNCH[j]++;
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
    for(int j=info[i].dinner_start; j<=info[i].dinner_end; j++) DINNER[j]++;
  }
  int ans = 0;
  for (int i = 0; i < MAX_TIME; i++) {
    ans = max(ans, min({MORNING[i], LUNCH[i], DINNER[i]}));
  }
  cout << ans << "\n";
  return 0;
}