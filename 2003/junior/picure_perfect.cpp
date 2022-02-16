/*

*/
#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void solve(){
    double a, l, w;
    cin >> a;
    while(a != 0){
        w = round(sqrt(a));
        while(fmod(a, w) != 0){
            w--;
        }
        l = a / w;
        cout << "Minimum perimeter is " << 2 * (l + w)  << " with dimensions " << w << " x " << l << "\n";
        cin >> a;
    }
}

int main(void){
    solve();
    return 0;
}