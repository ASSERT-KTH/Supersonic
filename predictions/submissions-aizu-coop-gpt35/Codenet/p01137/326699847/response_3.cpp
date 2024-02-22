#include <iostream>
#include <cmath>

int main() {
    int e;
    while (std::cin >> e, e) {
        long long m = 1000000;
        int val;
        int val2;
        int y;
        int z = 100;
        
        while (z >= 0) {
            val = z * z * z;
            if (val > e) {
                --z;
                continue;
            }
            
            y = std::sqrt(e - val);
            while (y >= 0) {
                val2 = val + y * y;
                if (val2 > e) {
                    --y;
                    continue;
                }
                
                m += (e - val2) + y + z;
                --y;
            }
            
            --z;
        }
        
        std::cout << m << std::endl;
    }
    
    return 0;
}