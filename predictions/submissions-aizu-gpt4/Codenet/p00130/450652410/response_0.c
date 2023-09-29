#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    int T;
    cin >> T;
    cin.ignore();
    while(T--)
    {
        deque<char> train;
        char a, b, c;
        while((a = cin.get()) != '\n' && a != EOF)
        {
            b = cin.get();
            c = cin.get();
            cin.ignore();
            if(a == '<' && b == '-')
                train.push_front(c);
            else if(a == '-' && b == '>')
                train.push_back(c);
        }
        for(const auto& t : train)
            cout << t;
        cout << "\n";
        if(a == EOF)
            break;
    }
    return 0;
}