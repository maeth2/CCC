/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int key[30][2];
    for(int i = 0; i < 30; i++){
        key[i][0] = i % 6;
        key[i][1] = (i - key[i][0]) / 5;
    }
    string location;
    getline(cin, location);
    
    int previous[2] = {0, 0};
    int moves = 0;
    for(char c : location){
        int i = c - 'A';
        if(c == ' ') i = 26;
        else if(c == '-') i = 27;
        else if(c == '.') i = 28;
        moves += abs(previous[0] - key[i][0]) + abs(previous[1] - key[i][1]); 
        previous[0] = key[i][0];
        previous[1] = key[i][1];
    }
    moves += abs((previous[0] - key[29][0]) + (previous[1] - key[29][1]));
    cout << moves << "\n";
}

int main(void){
    solve();
    return 0;
}