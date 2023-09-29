#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    unordered_map<string, bool> dic;
    string opstr, str;
    cin >> n;
    while(n--){
        cin >> opstr >> str;
        if(opstr[0] == 'i'){
            dic[str] = true;
        }else if(opstr[0] == 'f'){
            if(dic[str]){
                cout << "yes\n";
            }else{
                cout << "no\n";
            }
        }
    }
    return 0;
}