/*

*/
#include <iostream>

using namespace std;
using ll = long long;

int price[4][4] = {{461, 431, 420, 0}, {100, 57, 70, 0}, {130, 160, 118, 0},  {167, 266, 75, 0}};

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << "Your total Calorie count is " << price[0][a - 1] + price[1][b - 1] + price[2][c - 1] + price[3][d - 1] << ".\n";
}

int main(void){
    solve();
    return 0;
}