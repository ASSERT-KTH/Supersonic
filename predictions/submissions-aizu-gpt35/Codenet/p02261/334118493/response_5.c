#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char suit;
    int value;
} Card;

void swap_Card(Card *x, Card *y) {
    Card temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(Card A[], int N) {
    int i, j;
    Card temp;
    int flag = 1;
    for (i = 0; flag; i++) {
        flag = 0;
        for (j = N - 1; j >= i + 1; j--) {
            if (A[j].value < A[j - 1].value) {
                swap_Card(&A[j], &A[j - 1]);
                flag = 1;
            }
        }
    }
}

void SelectionSort(Card A[], int N) {
    int i, j;
    int minj;
    Card temp;
    for (i = 0; i < N - 1; i++) {
        minj = i;
        for (j = i + 1; j < N; j++) {
            if (A[j].value < A[minj].value) {
                minj = j;
            }
        }
        swap_Card(&A[i], &A[minj]);
    }
}

int main() {
    int N;
    scanf("%d\n", &N);
    int i, j;
    Card* BC = (Card*)malloc(sizeof(Card) * N);
    Card* SC = (Card*)malloc(sizeof(Card) * N);
    for (i = 0; i < N; i++) {
        Card c;
        scanf("%c", &c.suit);
        scanf("%d ", &c.value);
        BC[i] = c;
        SC[i] = c;
    }
    BubbleSort(BC, N);
    SelectionSort(SC, N);
    for (i = 0; i < N - 1; i++) {
        printf("%c%d ", BC[i].suit, BC[i].value);
    }
    printf("%c%d\n", BC[N - 1].suit, BC[N - 1].value);
    if (BC != SC) {
        puts("Not stable");
    }
    else {
        puts("Stable");
    }
    for (i = 0; i < N - 1; i++) {
        printf("%c%d ", SC[i].suit, SC[i].value);
    }
    printf("%c%d\n", SC[N - 1].suit, SC[N - 1].value);
    if (BC != SC) {
        puts("Not stable");
    }
    else {
        puts("Stable");
    }
    free(BC);
    free(SC);
    return 0;
}