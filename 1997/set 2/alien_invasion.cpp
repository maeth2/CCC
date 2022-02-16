/*
Alien Invasion

Earth is being invaded by space aliens. Earth defence forces have rallied a number of anti-spacecraft guns. However, 
they have a bug in their aiming hardware: initially they are aimed straight up, and this aim can only be adjusted downward.
Thousands of alien craft are streaking towards Earth as we speak -- and yes, some of them are even aimed at Canada. 
The Earth defence forces must now come into play. Each gun can fire as many shots as necessary, and can be re-fired 
as often and as quickly as necessary, but only to a lower setting. Thus if a spacecraft came in at height 3 and then 
another at height 2, one gun could eliminate both, but could not if they came in the other order. The Earth has only a 
finite number of guns and it is unknown how many alien craft are coming in. Thus they need a way to minimize the number
of guns for a given set of incoming alien craft. Guess what? This is where you come in!

*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int solve(){
    int n;
    cin >> n;
    vector<float> heights;
    for(int i = 0; i < n; i++){
        float a;
        cin >> a;
        heights.push_back(a);
    }

    int ans = 0;

    while(heights.size() > 0){
        float curr = -1;
        for(int i = heights.size() - 1; i >= 0; i--){
            if(heights[i] >= curr){
                curr = heights[i];
                heights.erase(heights.begin() + i);
            }
        }
        ans++;
    }

    cout << ans;
}

int main(){
    solve();
}