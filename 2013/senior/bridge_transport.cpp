/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int w, n;
    cin >> w >> n;
    vector<int> trucks(n);
    int total = 0;
    int cars = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        trucks[i] = a;
    }
    for(int i = 0; i < n; i++){
        total += trucks[i];
        if(i >= 4){
            total -= trucks[i - 4];
        }
        if(total > w){
            cout << i << '\n';
            break;
        }
        if(i == n - 1){
            cout << n << '\n';
        }
    }
}

int main(void){
    solve();
    return 0;
}