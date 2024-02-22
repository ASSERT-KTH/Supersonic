#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long int e;
    while (cin >> e, e) {
        long long int m = 1000000;
        long long int e_cbrt = cbrt(e); // Calculate the cube root of 'e'
        
        for (long long int z = e_cbrt; z >= 0; --z) {
            long long int val = z * z * z;
            
            if (val > e)
                continue;
            
            long long int e_minus_val = e - val;
            long long int sqrt_e_minus_val = sqrt(e_minus_val); // Calculate the square root of the difference between 'e' and 'val'
            
            for (long long int y = sqrt_e_minus_val; y >= 0; --y) {
                long long int val2 = val + y * y;
                
                if (val2 > e)
                    continue;
                
                m = min(m, (e - val2) + y + z);
            }
        }
        cout << m << endl;
    }
    return 0;
}