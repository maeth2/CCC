/*

*/
#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    int dt, et, wt, a, b;
    cin >> dt >> et >> wt;
    int d = dt - 100 > 0 ?  dt - 100 : 0;
    d *= 25;
    int e = 15 * et;
    int w = 20 * wt;

    a = d + e + w;
    cout << "Plan A costs " << a / 100.0 << "\n";

    d = dt - 250 > 0 ? dt - 250 : 0;
    d *= 45;
    e = 35 * et;
    w = 25 * wt;

    b = d + e + w;

    cout << "Plan B costs " << b / 100.0 << "\n";

    if(a > b) cout << "Plan B is cheapest.\n";
    else if(a < b) cout << "Plan A is cheapest.\n";
    else cout << "Plan A and B are the same price.\n";
}

int main(void){
    solve();
    return 0;
}