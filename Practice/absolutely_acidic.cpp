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
    vector<int> r(1001);
    int maxn = 0;
    int maxn2 = 0;
    int maxi = 0;
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int r1;
        cin >> r1;
        r[r1]++;
        if(r1 != maxi){
            if(r[r1] > maxn){
                maxn2 = maxn;
                maxi = r1;
                maxn = r[r1]; 
            }else if(r[r1] > maxn2){
                maxn2 = r[r1];
            }
        }else{
            maxn = r[r1];
        }
    }

    for(int i = 0; i < 1000; i++){
        if(r[i] == maxn){
            maxi = i;
            for(int j = 1; j < 1000; j++){
                if(r[j] == maxn2){
                    ans = max(abs(maxi - j), ans);
                }
            }
        }
    }
    
    
    cout << ans << "\n";
}

int main(void){
    solve();
    return 0;
}