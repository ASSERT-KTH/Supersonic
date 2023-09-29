#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char suit;
    int value;
} Card;

void bubble_sort(Card *A, int N) {
    int i, j;
    for (i = 0; i < N - 1; i++) {
        int flag = 0;
        for (j = N - 1; j > i; j--) {
            if (A[j].value < A[j - 1].value) {
                Card temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = 1;
            }
        }
        if (!flag) {
            break;
        }
    }
}

void selection_sort(Card *A, int N) {
    int i, j;
    for (i = 0; i < N - 1; i++) {
        int minj = i;
        for (j = i + 1; j < N; j++) {
            if (A[j].value < A[minj].value) {
                minj = j;
            }
        }
        if (minj != i) {
            Card temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Card *BC = (Card*)malloc(sizeof(Card)*N);
    Card *SC = (Card*)malloc(sizeof(Card)*N);
    int i;
    for (i = 0; i < N; i++) {
        scanf(" %c %d", &BC[i].suit, &BC[i].value);
        SC[i] = BC[i];
    }
    bubble_sort(BC, N);
    selection_sort(SC, N);
    for (i = 0; i < N; i++) {
        printf("%c%d ", BC[i].suit, BC[i].value);
    }
    printf("\nStable\n");
    for (i = 0; i < N; i++) {
        printf("%c%d ", SC[i].suit, SC[i].value);
    }
    printf("\n");
    for (i = 0; i < N; i++) {
        if (BC[i].suit != SC[i].suit) {
            printf("Not stable\n");
            break;
        }
        if (i == N - 1) {
            printf("Stable\n");
        }
    }
    free(BC);
    free(SC);
    return 0;
}