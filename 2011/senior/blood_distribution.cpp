/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int blood[8];
int patient[8];
void solve(){
    for(int i = 0; i < 8; i++) cin >> blood[i];
    for(int i = 0; i < 8; i++) cin >> patient[i];
    // start with o- then o+ then a-, then b -, then a + , then b+, then AB-, then AB+
    //
}

int main(void){
    solve();
    return 0;
}