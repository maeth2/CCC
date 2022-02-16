/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int alphaA[26];
int alphaB[26];

void solve(){
    string a, b;
    getline(cin, a);
    getline(cin, b); 
    for(int i = 0; i < a.size(); i++){
        if(a[i] == ' ') continue;
        int index = a[i] - 'A';
        alphaA[index]++;
    }
    for(int i = 0; i < b.size(); i++){
        if(b[i] == ' ') continue;
        int index = b[i] - 'A';
        alphaB[index]++;
    }
    bool same = true;
    for(int i = 0; i < 26; i++){
        if(alphaA[i] != alphaB[i]){
            same = false;
            break;
        }
    }
    if(same){
        cout << "Is an anagram.\n";
    }else{
        cout << "Is not an anagram.\n";
    }
}

int main(void){
    solve();
    return 0;
}