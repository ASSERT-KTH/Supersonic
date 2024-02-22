#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numbers[6];
    for(int i=0; i<6; i++)
        cin >> numbers[i];

    sort(numbers, numbers+6);

    int ans = numbers[1] + numbers[2] + numbers[3] + numbers[4] + max(numbers[5],numbers[0]);
    cout << ans << "\n";
    return 0;
}