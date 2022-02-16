/*

*/
#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    int x, y;
    cin >> x >> y;
    for(int i = 0; i <= y - x; i++){
        if(i % 4 == 0 && i % 2 == 0 && i % 3 == 0 && i % 5 == 0) cout << "All positions change in year " << x + i << "\n";
    }
}

int main(void){
    solve();
    return 0;
}