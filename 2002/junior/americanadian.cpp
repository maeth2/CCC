/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    string vowels = "aeiouy";
    string c;
    cin >> c;
    while(c != "quit!"){
        if(c.size() > 4 && c.substr(c.size() - 2, 2) == "or" && vowels.find(c[c.size() - 3]) == vowels.npos){
            cout << c.substr(0, c.size() - 2) << "our\n";
        }else{
            cout << c << "\n";
        }
        cin >> c;
    }
}

int main(void){
    solve();
    return 0;
}