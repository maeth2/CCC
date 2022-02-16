/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int n = 0;
    int k = -1;
    int sw[100000];
    int se[100000];
    cin >> n;
    for(int i = 0; i < n; i++){
        int j;
        cin >> j;
        if(i == 0){
            sw[i] = j;
            continue;
        }
        sw[i] = sw[i - 1] + j;
    }
    for(int i = 0; i < n; i++){
        int j;
        cin >> j;
        if(i == 0){
            se[i] = j;
            continue;
        }
        se[i] = se[i - 1] + j;
    }
    for(int i = 0; i < n; i++){
        if(se[i] == sw[i]){
            k = i;
        } 
    }
    cout << k + 1 << '\n';
}

int main(void){
    solve();
    return 0;
}