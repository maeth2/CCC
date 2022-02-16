/*

*/
#include <iostream>

using namespace std;
using ll = long long;

int max(int a, int b){return a > b ? a : b;}
int min(int a, int b){return a < b ? a : b;}

void solve(){
    int bowls[3];
    cin >> bowls[0] >> bowls[1] >> bowls[2];
    int mx = max(bowls[0], max(bowls[1], bowls[2]));
    int mi = min(bowls[0], min(bowls[1], bowls[2]));
    for(int i = 0; i < 3; i++){
        if(mx != bowls[i] && mi != bowls[i]){
            cout << bowls[i];
        }
    }
}

int main(void){
    solve();
    return 0;
}