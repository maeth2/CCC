/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int y;
    cin >> y;
    y++;
    while(true){
        int n = y;
        vector<bool> digits(9);
        bool found = true;
        //cout << i << "\n";
        while(n != 0){
            int a = n % 10;
            if(digits[a]){
                found = false;
                break;
            }else{
                digits[a] = true;
            }
            n -= a;
            n /= 10;
        }
        if(found){
            cout << y << "\n";
            break;
        }
        y++;
    }    
}

int main(void){
    solve();
    return 0;
}