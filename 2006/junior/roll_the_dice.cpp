/*

*/
#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    int a, b;
    cin >> a >> b;
    int c = a > b ? a : b;
    int d = a < b ? a : b;
    int ans = 0;
    for(int i = c; i > 0 && 10 - i <= d; i--){
        if(10 - i <= 0) continue;
        ans++;
    }
    if(ans == 1) cout << "There is 1 way to get the sum 10.\n";
    else cout << "There are " << ans << " ways to get the sum 10.\n";
}

int main(void){
    solve();
    return 0;
}