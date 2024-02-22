#define SIZE 99
#define BITS_PER_BYTE 5

char R[SIZE];
int i, h, b;

int main(int c) {
    for (i = 0; read(0, &c, 1); ++i)
    {
        if (i > 9) 
        {
            memset(R, 0, SIZE);
            printf("%d %d\n", h, b - h);
            i = h = b = 0;
        }
        b += R[c] != 0;
        h += (R[c] ^= 1 << i % BITS_PER_BYTE) == 0;
    }
    return 0;
}