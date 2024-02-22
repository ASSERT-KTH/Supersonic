#include <iostream>
#include <vector>
using namespace std;

bool canAlloc(vector<int>& weight, int num_packet, int num_track, long capacity) {
  int i = 0, track_id = 0;
  long alloced_in_one = 0;
  
  while (i < num_packet) {
    if (weight[i] > capacity) {
      return false;
    }
    while (i < num_packet && alloced_in_one + weight[i] <= capacity) {
      alloced_in_one += weight[i];
      i++;
    }
    alloced_in_one = 0;
    if (++track_id > num_track) {
      return false;
    }
  }
  return true;
}

int main(void) {
  int num_packet, num_track;
  cin >> num_packet >> num_track;
  vector<int> weight(num_packet);
  
  int max_weight = 0;
  long sum_weight = 0;
  for (int i = 0; i < num_packet; i++) {
    cin >> weight[i];
    if (weight[i] > max_weight) {
      max_weight = weight[i];
    }
    sum_weight += weight[i];
  }
  
  long low = max_weight, upp = sum_weight;

  while (low < upp) {
    long mid = low + ((upp - low) >> 1);
    if (canAlloc(weight, num_packet, num_track, mid)) {
      upp = mid;
    } else {
      low = mid + 1;
    }
  }

  cout << low << "\n";
  return 0;
}