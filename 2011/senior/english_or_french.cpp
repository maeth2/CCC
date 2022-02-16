/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    string line;
    int s, t = 0;
    getline(cin, line);
    for(int i = 0; i < n; i++){
        getline(cin, line);
        for(char c : line){
            if(c == 's' || c == 'S') s++;
            else if(c == 't' || c == 'T') t++;
        }
    }
    if(t <= s) cout << "French\n";
    else cout << "English\n";
}

int main(void){
    solve();
    return 0;
}