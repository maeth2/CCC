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
    vector<int> heights(n + 1);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }
    vector<int> ans(n, 1e9);
    for(int i = 0; i < n; i++){
        int a = 0;
        for(int j = 0; j <= i; j++){
            if(i - j < 0 || i + j >= n) break;
            a += abs(heights[i - j] - heights[i + j]);
            ans[j * 2] = min(ans[j * 2], a);
        }
    }

    for(int i = 0; i < n; i++){
        int a = 0;
        for(int j = 0; j <= i; j++){
            if(i - j < 0 || i + j + 1 >= n) break;
            a += abs(heights[i - j] - heights[i + j + 1]);
            ans[j * 2 + 1] = min(ans[j * 2 + 1], a);
        }
    }
    
    for(int i : ans) cout << i << ' ';
    cout << "\n";
}

int main(void){
    solve();
    return 0;
}