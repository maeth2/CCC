/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    string e = "9780921418";
    int total = 0;
    int m = 1;
    for(char i : e){
        int j = i - '0';
        total += j * m;
        if(m == 1) m = 3;
        else if(m == 3) m = 1;
    }
    for(int i = 0; i < 3; i++){
        int j;
        cin >> j;
        total += j * m;
        if(m == 1) m = 3;
        else if(m == 3) m = 1;
    }
    cout << "The 1-3-sum is " << total << "\n";
}

int main(void){
    solve();
    return 0;
}