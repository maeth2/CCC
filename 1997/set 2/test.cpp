/*

*/
#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;
using ll = long long;

int solve(){
    srand(time(0));
    for(int i = 0; i < 10; i++){
        cout << rand() % 100 << "\n";
    }
}

int main(void){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}