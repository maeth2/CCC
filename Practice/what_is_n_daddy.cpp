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
    int ans = 0;
    for(int i = (n / 2) + n % 2; i <= n; i++){
        int a = n - i;
        if(a > 5 || i > 5) continue;
        ans++;
        //cout << i << ' ' << a << "\n";
    }
    cout << ans << '\n';
}

int main(void){
    solve();
    return 0;
}