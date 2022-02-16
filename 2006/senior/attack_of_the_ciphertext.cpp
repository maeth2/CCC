/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

char c[27];

void solve(){
    string plain, cipher, msg;
    getline(cin, plain);
    getline(cin, cipher);
    getline(cin, msg);
    for(int i = 0; i < 27; i++){
        c[i] = '.';
    }
    for(int i = 0; i < plain.size(); i++){
        int index = -1;
        if(cipher[i] == ' '){
            index = 26;
        }else{
            index = cipher[i] - 'A';
        }
        c[index] = plain[i];
    }

    for(char i : msg){
        int index = -1;
        if(i == ' '){
            index = 26;
        }else{
            index = i - 'A';
        }
        cout << c[index];
    }
}

int main(void){
    solve();
    return 0;
}