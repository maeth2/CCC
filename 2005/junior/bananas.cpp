/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    string word;
    cin >> word;
    while(word != "X"){
        bool found = true;
        while(found){
            found = false;
            if(word.size() >= 3){
                for(int i = 0; i < word.size() - 2; i++){
                    if(word.substr(i, 3) == "ANA" || word.substr(i, 3) == "BAS"){
                        word = (word.size() > 3 ? word.substr(0, i) : "") + "A" + (word.size() > i + 3 ? word.substr(i + 3, word.size() - (i + 3)) : "");
                        found = true;
                        break;
                    }
                }
            }
        }        
        if(word == "A") cout << "YES\n";
        else cout << "NO\n";
        cin >> word;
    }
}

int main(void){
    solve();
    return 0;
}