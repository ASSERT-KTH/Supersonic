#include <iostream>

void cubedNum()
{
    int inputNum;
    while (std::cin >> inputNum && (inputNum < 0 || inputNum > 100));

    std::cout << inputNum * inputNum * inputNum << '\n';
}

int main()
{
    cubedNum();
    return 0;
}