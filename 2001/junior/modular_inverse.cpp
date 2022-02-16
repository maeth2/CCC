/*

*/
#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    int m, n;
    cin >> m >> n;
    bool found = false;
    for(int i = 1; i < n; i++){
        if((m * i) % n == 1){
            cout << i << "\n";
            found = true;
            break;
        }
    }
    if(!found) cout << "No such integer exists.";
}

int main(void){
    solve();
    return 0;
}