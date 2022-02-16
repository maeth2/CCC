/*

*/
#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void solve(){
    double n;
    cin >> n;
    n = floor(sqrt(n));
    cout << "The largest square has side length " << n << ".\n";
}

int main(void){
    solve();
    return 0;
}