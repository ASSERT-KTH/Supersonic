#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[6];
    for(int i=0; i<4; ++i) cin >> arr[i];
    for(int i=4; i<6; ++i) cin >> arr[i];
    nth_element(arr, arr+3, arr+4);
    nth_element(arr+4, arr+5, arr+6);
    cout << accumulate(arr+1, arr+6, 0) << endl;
    return 0;
}