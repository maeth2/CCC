/*

*/
#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void solve(){
    int a, b, ans = 0;
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        int t = 0;
        for(int j = 1; j <= sqrt(i); j++){
            if(i % j == 0){
                if(j * j == i) t += 1;
                else t += 2;
                if(t > 4) break;
            }
        }
        if(t == 4){
            ans++;
        }
    }
    cout << "The number of RSA numbers between " << a << " and " << b << " is " << ans << "\n";
}

int main(void){
    solve();
    return 0;
}