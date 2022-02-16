/*
Martha takes a jar of quarters to the casino with the intention of becoming rich. She plays
three machines in turn. Unknown to her, the machines are entirely predictable. Each play
costs one quarter. The first machine pays 30 quarters every 35th time it is played; the
second machine pays 60 quarters every 100th time it is played; the third pays 9 quarters
every 10th time it is played.
*/
#include <iostream>

using namespace std;
using ll = long long;

int solve(){
    int q;
    int machines[3];
    int machines_payouts[3][2] = {{30, 35}, {60, 100}, {9,10}};
    //cout << "How many quarters does Martha have in the jar?\n";
    cin >> q;
    //cout << "How many times has the first machine been played since paying out?\n";
    cin >> machines[0];
    //cout << "How many times has the second machine been played since paying out?\n";
    cin >> machines[1];
    //cout << "How many times has the third machine been played since paying out?\n";
    cin >> machines[2];
    int ans = 0;
    int turn = 0;
    while(q > 0){
        machines[turn]++;
        q--;
        if(machines[turn] == machines_payouts[turn][1]){
            machines[turn] = 0;
            q += machines_payouts[turn][0];
        }
        turn++;
        if(turn >= 3){
            turn = 0;
        }
        ans++;
    }
    cout << "Martha plays " << ans << " times before going broke.";
}

int main(void){
    solve();
    return 0;
}