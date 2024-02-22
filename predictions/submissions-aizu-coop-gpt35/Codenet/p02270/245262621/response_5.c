#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PACKET 100000

int num_packet;
int num_track;
int* weight;

bool canAlloc(long capacity);

int main(void) {
    int i;
    scanf("%d %d", &num_packet, &num_track);

    weight = (int*)malloc(sizeof(int) * num_packet);  // Dynamically allocate memory for the weight array

    int max_weight = 0;
    long sum_weight = 0;
    for (i = 0; i < num_packet; i++) {
        scanf("%d", &weight[i]);
        if (weight[i] > max_weight) {
            max_weight = weight[i];
        }
        sum_weight += weight[i];
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

    free(weight);  // Free the dynamically allocated memory

    return 0;
}

bool canAlloc(long capacity) {
    long i = 0;
    long current_track_weight = 0;  // Variable to keep track of the current track's allocation
    int track_id = 0;

    for (i = 0; i < num_packet; i++) {
        if (current_track_weight + weight[i] <= capacity) {
            current_track_weight += weight[i];
        } else {
            current_track_weight = 0;
            i--;
            if (++track_id == num_track) {
                return false;
            }
        }
    }

    return true;
}