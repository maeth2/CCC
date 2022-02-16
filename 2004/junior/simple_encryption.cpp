/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    string key, code;
    cin >> key;
    
    getline(cin, code);
    getline(cin, code);

    int j = 0;
    for(int i = 0; i < code.size(); i++){
        int k = key[j % key.size()] - 'A';
        code[i] += k;
        if(code[i] >= 26 + 'A') code[i] = code[i] - 26;
        if(code[i] != ' ' && code[i] >= 'A' && code[i] <= 'Z'){
            cout << code[i];
            j++;
        }       
    }
    cout << "\n";
}

int main(void){
    solve();
    return 0;
}