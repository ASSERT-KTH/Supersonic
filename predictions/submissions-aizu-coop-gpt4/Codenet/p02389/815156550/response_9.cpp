#include <iostream>

int main() {
   int a;
   int b;
   std::cin >> a >> b;
   
   // Factoring out the common multiplier '2' to reduce the multiplication operation
   std::cout << a * b << " " << 2 * (a + b) << std::endl;
}