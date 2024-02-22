#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    int front;
    int rear;
    int capacity;
} Deque;

Deque* create_deque(int capacity) {
    Deque* deque = malloc(sizeof(Deque));
    deque->data = malloc(capacity * sizeof(char));
    deque->front = deque->rear = -1;
    deque->capacity = capacity;
    return deque;
}

void append_left(Deque* deque, char c) {
    if (deque->front == -1) {
        deque->front = deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = deque->capacity - 1;
    } else {
        --deque->front;
    }
    deque->data[deque->front] = c;
}

void append_right(Deque* deque, char c) {
    if (deque->rear == -1) {
        deque->front = deque->rear = 0;
    } else if (deque->rear == deque->capacity - 1) {
        deque->rear = 0;
    } else {
        ++deque->rear;
    }
    deque->data[deque->rear] = c;
}

bool ope_line() {
    int n;
    scanf("%d\n", &n);
    Deque* train = create_deque(52);
    for (int i = 0; i < n; ++i) {
        char operation[4];
        fgets(operation, sizeof(operation), stdin);
        char c = getchar();
        if (strcmp(operation, "<-\0") == 0) {
            append_left(train, c);
        } else if (strcmp(operation, "->\0") == 0) {
            append_right(train, c);
        }
    }
    for (int i = train->front; i != train->rear; i = (i + 1) % train->capacity) {
        putchar(train->data[i]);
    }
    putchar('\n');
    free(train->data);
    free(train);
    return getchar() != EOF;
}

int main(int argc, char **argv) {
    while (ope_line());
    return 0;
}