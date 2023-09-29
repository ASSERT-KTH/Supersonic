#include <iostream>
#include <deque>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore();

    while(n--)
    {
        std::deque<char> train;
        char direction, arrow, c;
        while(std::cin >> direction >> arrow >> c && direction != '\n' && direction != EOF)
        {
            if(direction == '<' && arrow == '-')
                train.push_front(c);
            else if(direction == '-' && arrow == '>')
                train.push_back(c);
        }
        for(const auto& e : train)
            std::cout << e;
        std::cout << "\n";
    }
    return 0;
}