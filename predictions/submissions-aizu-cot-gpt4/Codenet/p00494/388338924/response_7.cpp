#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string x;
    std::cin >> x;
    int a = 0, b = 0, c = 0, d = 0, maxi = 0;

    for (char ch : x) {
        switch (ch) {
            case 'J':
                b++; 
                a = 0;
                break;
            case 'O':
                c = std::min(b, a); 
                a = 0;
                break;
            case 'I':
                d = std::min(c, a); 
                a = 0;
                break;
            default:
                a++;
                break;
        }
        maxi = std::max(maxi, d);
        if (ch != 'I') {
            b = 0;
            c = 0;
            d = 0;
        }
    }
    std::cout << maxi << std::endl;
    return 0;
}