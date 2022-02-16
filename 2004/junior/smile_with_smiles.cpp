/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    string adjective[5];
    string noun[5];
    for(int i = 0; i < n; i++) cin >> adjective[i];
    for(int i = 0; i < m; i++) cin >> noun[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << adjective[i] << " as " << noun[j] << "\n";
        }
    }

}

int main(void){
    solve();
    return 0;
}