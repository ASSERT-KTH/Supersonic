#include <iostream>
#include <bitset>
#define MAX_NUM 100

std::bitset<MAX_NUM> numbers;
int num, count = 0;

int getNum() {
    std::cin >> num;
    return num;
}

int main() {
    for (int i = getNum(); i--; ) {
        if (!numbers[getNum()]) {
            numbers.set(num);
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}