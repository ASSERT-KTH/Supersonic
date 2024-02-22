#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    std::cin >> x;
    
    int square_x = x * x;
    int cube_x = square_x * x;
    
    std::cout << cube_x << "\n";
    return 0;
}