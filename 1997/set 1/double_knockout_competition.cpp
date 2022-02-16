/*
In a number of sports, a championship may be determined by a double knockout competition. A
team is eliminated on its second loss, so the winner is the last remaining team with one or fewer
losses. The competition is played is a series of rounds: in each round, teams that have not been
eliminated are paired subject to the constraint that an undefeated team never plays a team with
one loss. As many teams as possible are paired in each round. After a number of rounds only
two teams remain. These teams play in a round by themselves, although one is undefeated and
the other is not. If neither is eliminated, they play again in a final round. For our analysis we
assume that this extra round is always necessary.
a) Write a program to report on a Double Knockout Competition.
*/
#include <iostream>

using namespace std;

int solve(){
    int n;
    cin >> n;

    int total = n;
    int undefeated = n;
    int one_loss = 0;
    int eliminated = 0;
    int round = 0;

    while(one_loss + undefeated >= 1){
        cout << "Round " << round << ":" << undefeated << " undefeated, " << one_loss << " one loss, " << eliminated << " eliminated\n";
        if(one_loss + undefeated == 1) break;
        if(!(undefeated == 1 && one_loss == 1)){
            int a = 0, b = 0;
            int odd = undefeated % 2;
            if(undefeated - odd > 0) a = (undefeated - odd) / 2;
            odd = one_loss % 2;
            if(one_loss - odd> 0) b = (one_loss - odd) / 2;
            undefeated -= a;
            one_loss -= b;
            one_loss += a;
            eliminated += b;
        }else{
            if(undefeated == 1){
                undefeated = 0;
                one_loss = 2;
            }else{
                one_loss = 1;
                eliminated ++;
            }
        }
        round++;
    }
    cout << "There are " << round << " rounds\n";
    
}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}