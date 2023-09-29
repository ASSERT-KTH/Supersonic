#include <iostream>
#include <algorithm>
#define MAX_PACKET 100000
using namespace std;

int num_packet;
int num_track;
int weight[MAX_PACKET];

bool canAlloc(long long capacity) {
  int track_id = 0;
  long long temp = 0;
  for (int i = 0; i < num_packet; i++) {
    if (temp + weight[i] > capacity) {
      temp = weight[i];
      if (++track_id == num_track) return false;
    }
    else temp += weight[i];
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> num_packet >> num_track;
  long long max_weight = 0;
  long long sum_weight = 0;
  for (int i = 0; i < num_packet; i++) {
    cin >> weight[i];
    max_weight = max((long long)weight[i], max_weight);
    sum_weight += weight[i];
  }
  long long low = max_weight, upp = sum_weight;
  while (low < upp) {
    long long mid = low + ((upp - low) / 2);
    if (canAlloc(mid)) upp = mid;
    else low = mid + 1;
  }
  cout << low << '\n';
  return 0;
}