#include <stdio.h>

typedef struct {
    char suit;
    int value;
} Card;

void swap_Card(Card *x, Card *y) {
    Card temp = *x;
    *x = *y;
    *y = temp;
}

void MergeSort(Card A[], int left, int right) {
    if (right - left > 1) {
        int mid = left + (right - left) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid, right);
        Card buf[36];
        int buf_index = 0;
        int i = left;
        int j = mid;
        while (i < mid && j < right) {
            if (A[i].value <= A[j].value)
                buf[buf_index++] = A[i++];
            else
                buf[buf_index++] = A[j++];
        }
        while (i < mid)
            buf[buf_index++] = A[i++];
        while (j < right)
            buf[buf_index++] = A[j++];
        for (i = left; i < right; i++)
            A[i] = buf[i - left];
    }
}

void print_Cards(Card A[], int N) {
    int i;
    for (i = 0; i < N - 1; i++)
        printf("%c%d ", A[i].suit, A[i].value);
    printf("%c%d\n", A[N - 1].suit, A[N - 1].value);
}

int main() {
    int N;
    scanf("%d\n", &N);
    int i;
    Card BC[36];
    Card SC[36];
    for (i = 0; i < N; i++) {
        Card c;
        scanf("%c", &c.suit);
        scanf("%d ", &c.value);
        BC[i] = c;
        SC[i] = c;
    }
    MergeSort(BC, 0, N);
    MergeSort(SC, 0, N);
    print_Cards(BC, N);
    puts("Stable");
    print_Cards(SC, N);
    for (i = 0; i < N; i++) {
        if (BC[i].suit != SC[i].suit) {
            puts("Not stable");
            return 0;
        }
    }
    puts("Stable");
    return 0;
}