#include <stdio.h>
#define N 2

int matrix(double **x);

int main(void) {
    double x[N][N + 1];
    double *y[N];
    char str[100];

    while(fgets(str, sizeof(str), stdin)) {
        sscanf(str, "%lf %lf %lf %lf %lf %lf", &x[0][0], &x[0][1], &x[0][2], &x[1][0], &x[1][1], &x[1][2]);

        for (int i = 0; i < N; i++)
            y[i] = x[i];

        matrix(y);

        for (int i = 0; i < N; i++) {
            if (i)
                printf(" ");
            printf("%3.3f", x[i][N]);
        }
        printf("\n");
    }

    return 0;
}

int matrix(double **x) {
    double su1, su2;

    // Fully unrolling the loop
    su1 = x[0][0];
    su2 = x[1][0];
    x[1][0] = x[1][0] - x[0][0] * su2 / su1;
    x[1][1] = x[1][1] - x[0][1] * su2 / su1;
    x[1][2] = x[1][2] - x[0][2] * su2 / su1;

    su1 = x[1][1];
    su2 = x[0][1];
    x[0][0] = x[0][0] - x[1][0] * su2 / su1;
    x[0][1] = x[0][1] - x[1][1] * su2 / su1;
    x[0][2] = x[0][2] - x[1][2] * su2 / su1;

    su1 = x[0][0];
    x[0][0] = x[0][0] / su1;
    x[0][1] = x[0][1] / su1;
    x[0][2] = x[0][2] / su1;

    su1 = x[1][1];
    x[1][0] = x[1][0] / su1;
    x[1][1] = x[1][1] / su1;
    x[1][2] = x[1][2] / su1;

    return 0;
}