/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int t;
    cin >> t;
    for(int cases = 0; cases < t; cases++){
        int n;
        cin >> n;
        vector<int> mountain;
        vector<int> branch;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            mountain.push_back(a);
        }

        int next = 1;
        bool action = true;
        while(next <= n && action){
            action = false;
            if(!mountain.empty() && mountain.back() == next){
                mountain.pop_back();
                next++;
                action = true;
                continue;
            }else if(!branch.empty() && branch.back() == next){
                branch.pop_back();
                next++;
                action = true;
                continue;
            }else if(!mountain.empty()){
                branch.push_back(mountain.back());
                mountain.pop_back();
                action = true;
                continue;
            }
        }

        if(next > n) cout << 'Y' << "\n";
        else cout << 'N' << '\n';
    }
}

int main(void){
    solve();
    return 0;
}