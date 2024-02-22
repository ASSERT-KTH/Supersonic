#include <iostream>
using namespace std;

// Faster method for reading integers
inline int fast_read() {
    int n = 0;
    char c;
    while ((c = getchar_unlocked()) >= '0') {
        n = 10 * n + (c - '0');
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(false); // Faster I/O
    cin.tie(NULL);

    int n, m, a;
    int amida[101][1001] = {{0}};
    while (true) {
        n = fast_read();
        m = fast_read();
        a = fast_read();
        
        if (n == 0 && m == 0 && a == 0) {
            break;
        }
        
        // Reset the array
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 1001; j++)
                amida[i][j] = 0;
        
        for (int i = 0; i < m; i++) {
            int h = fast_read();
            int p = fast_read();
            int q = fast_read();
            amida[p][h] = 1;
        }
        for (int j = 1000; j > 0; j--) {
            if (amida[a][j] == 1)
                a++;
            else if (amida[a - 1][j] == 1)
                a--;
        }
        cout << a << "\n";
    }
    return 0;
}