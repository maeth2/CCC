/*

*/
#include <iostream>

using namespace std;
using ll = long long;

int prices[10] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
int total = 1691600;
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        total -= prices[c - 1];
    }
    int offer;
    cin >> offer;

    int average = total / (10 - n);
    if(offer < average){
        cout << "no deal";
    }else{
        cout << "deal";
    }
}

int main(void){
    solve();
    return 0;
}