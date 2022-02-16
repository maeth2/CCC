/*
Roberta the Robot plays a perfect game of golf. When she hits the golf ball it always goes
directly towards the hole on the green, and she always hits exactly the distance that is
specified for the club. Each such action is known as a stroke, and the object of golf is to
hit the ball from the tee to the hole in the fewest number of strokes. Roberta needs a
program to select the best combination of clubs to reach the hole in the fewest strokes.
She also needs to decide if the task is impossible, in which case she graciously
acknowledges the loss. Roberta can carry up to 32 clubs, and the total distance from the
tee to the hole does not exceed 5280 metres.
*/

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve(){
    int distance, n;
    cin >> distance >> n;
    vector<int> clubs(n);

    for(int i = 0; i < n; i++){
        cin >> clubs[i];
    }

    vector<int> f(distance + 1);
    f[0] = 0;

    for(int i = 1; i <= distance; i++){
        int min = INT16_MAX;
        for(int j = 0; j < clubs.size(); j++){
            int t = i - clubs[j];
            if(t >= 0 && f[t] >= 0 && f[t] < min){
                min = f[t];
            }
        }
        if(min < INT16_MAX){
            f[i] = min + 1;
        }else{
            f[i] = -1;
        }
    }

    int ans = f[distance];
    if(ans > -1) cout << "Roberta wins in " << ans << " strokes.\n";
    else cout << "Roberta acknowledges defeat.\n";
}

int main(void){
    solve();
    return 0;
}