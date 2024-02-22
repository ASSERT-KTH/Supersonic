// Replace the fixed-size array with a dynamically allocated array
int** data = new int*[Y];
for (int i = 0; i < Y; i++) {
    data[i] = new int[X];
}