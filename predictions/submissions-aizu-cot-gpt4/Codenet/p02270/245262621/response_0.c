#include <cstdlib>
#include <cstdio>
#include <vector>

int num_packet;
int num_track;
std::vector<int> weight;
bool canAlloc(long capacity);

int main(void) {
    scanf("%d %d", &num_packet, &num_track);
    weight.resize(num_packet);
    int max_weight = 0;
    long sum_weight = 0;
    for (int & w : weight) {
        scanf("%d", &w);
        if (w > max_weight) {
            max_weight = w;
        }
        sum_weight += w;
    }
    long low = max_weight;
    long upp = sum_weight;
    while (low < upp) {
        long mid = (low + upp) / 2;
        if (canAlloc(mid)) {
            upp = mid;
        } else {
            low = mid + 1;
        }
    }
    printf("%ld\n", low);
    return 0;
}

bool canAlloc(long capacity) {
    long alloced_in_one = 0;
    int track_id = 0;
    for (const int & w : weight) {
        if (alloced_in_one + w <= capacity) {
            alloced_in_one += w;
        } else {
            alloced_in_one = w;
            if (++track_id == num_track) {
                return false;
            }
        }
    }
    return true;
}