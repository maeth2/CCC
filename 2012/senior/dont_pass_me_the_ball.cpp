/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    int total = 0;
    for(int i = 1; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int z = j + 1; z < n; z++){
                total++;
            }
        }
    }
    cout << total;
}

int main(void){
    solve();
    return 0;
}