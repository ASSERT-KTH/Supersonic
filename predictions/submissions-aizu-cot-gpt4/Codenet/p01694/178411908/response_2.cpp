#include <iostream>
#include <string.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  while (cin >> n, n) {
    int ans = 0;
    char now[3] = "", next[3];
    for(int i=0; i<n; ++i) {
      cin >> next;
      if (!strcmp(now, "lu") && !strcmp(next, "ru"))
        ans++;
      else if (!strcmp(now, "ru") && !strcmp(next, "lu"))
        ans++;
      else if (!strcmp(now, "ld") && !strcmp(next, "rd"))
        ans++;
      else if (!strcmp(now, "rd") && !strcmp(next, "ld"))
        ans++;
      strcpy(now, next);
    }
    cout << ans << "\n";
  }
  return 0;
}