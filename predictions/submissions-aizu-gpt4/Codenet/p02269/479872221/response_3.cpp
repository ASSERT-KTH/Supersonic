#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    unordered_set<string> hashSet;
    int numOfCom;
    cin >> numOfCom;
    string com, word;

    while (numOfCom--)
    {
        cin >> com >> word;
        if (com[0] == 'i')
        {
            hashSet.insert(word);
        }
        else
        {
            if (hashSet.find(word) != hashSet.end())
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
    }

    return 0;
}