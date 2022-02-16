/*

*/
#include <iostream>
#include <math.h>

using namespace std;
using ll = long long;

void solve(){
    while(true){
        double r;
        cin >> r;
        if(r == 0) break;
        int num = 0;
        for(double i = 1; i <= r; i++){
            num += sqrt(r * r - i * i);
            num++;
        }
        
        num *= 4;
        num++;
        cout << num << "\n";
    }
}

int main(void){
    solve();
    return 0;
}