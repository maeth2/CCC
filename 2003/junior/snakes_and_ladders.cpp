/*

*/
#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    bool win = false;
    int current = 1;
    int roll;
    int paths[101];
    for(int i = 0; i < 101; i++) paths[i] = i;
    paths[54] = 19;
    paths[90] = 48;
    paths[99] = 77;
    paths[9] = 34;
    paths[40] = 64;
    paths[67] = 86;
    cin >> roll;
    while(!win && roll != 0){
        current += roll;
        if(current > 100){
            current -= roll;
        }
        current = paths[current];
        cout << "You are now on square " << current << "\n";
        if(current == 100){
            cout << "You Win!\n";
            win = true;
            break;
        }
        cin >> roll;
    }
    if(!win) cout << "You Quit!\n";
}

int main(void){
    solve();
    return 0;
}