/*
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int solve(){
    int n;
    cin >> n;
    int ans = 0;
    vector<int> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
        if(t[i]){
            ans += 3;
            if(i != 0 && t[i - 1]) ans -= 2;
        }
    }
    bool prev = 0;
    for(int i = 0; i < n; i++){
        bool c;
        cin >> c;
        if(c){
            ans += 3;
            if(i != 0 && prev) ans -= 2;
            if(i % 2 == 0 && t[i]) ans -= 2;
        }
        prev = c;
    }
    return ans; 
}

int main(void){
    cout << solve();
    return 0;
}