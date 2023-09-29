#include <iostream>
#include <cstring> // added to use memset function
using namespace std;
int k, ans;
int dif[12];
const int M = 10;

void rec(int d, int p, int *temp_dif) { // added temp_dif array
  if (p == k) {
    ans = d;
    return;
  }
  if (d >= ans)
    return;
  int rot = temp_dif[p]; // using temp_dif instead of dif
  if (rot == 0) {
    rec(d, p + 1, temp_dif); // passing temp_dif instead of dif
    return;
  }
  rec(d + 1, p + 1, temp_dif); // passing temp_dif instead of dif
  for (int i = p; i < k; i++) {
    temp_dif[i] = (temp_dif[i] - rot) % M; // using temp_dif instead of dif
    rec(d + 1, p + 1, temp_dif); // passing temp_dif instead of dif
  }
  for (int i = p; i < k; i++)
    temp_dif[i] = (temp_dif[i] + rot + M) % M; // using temp_dif instead of dif
}

int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    int temp_dif[12]; // creating temp_dif array
    memset(temp_dif, 0, sizeof(temp_dif)); // initializing temp_dif to 0
    for (int i = 0; i < k; i++) {
      temp_dif[i] = ((int)(t[i] - s[i]) + M) % M; // using temp_dif instead of dif
    }
    ans = k;
    rec(0, 0, temp_dif); // passing temp_dif instead of dif
    cout << ans << endl;
  }
}