/*

*/
#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void solve(){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int s = pow(a, 1/6);
    int power = pow(s, 6);
    while(power < a){
        s++;
        power = pow(s, 6);
    }
    while(power <= b){
        s++;
        power = pow(s, 6);
        ans++;
    }
    cout << ans << "\n";
}

int main(void){
    solve();
    return 0;
}