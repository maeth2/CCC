/*

*/
#include <iostream>

using namespace std;
using ll = long long;

int min(int a, int b){return a < b ? a : b;}

void solve(){
    int trout, pike, pickerel, limit, min, number;
    cin >> trout >> pike >> pickerel >> limit;
    for(int i = 0; i <= limit / trout; i++){
        for(int j = 0; j <= limit / pike; j++){
            for(int z = 0; z <= limit / pickerel; z++){
                int points = trout * i + pike * j + pickerel * z;
                if(points <= limit && points != 0){
                    number++;
                    cout << i << " Brown Trout, " << j << " Northern Pike, " << z << " Yellow Pickerel\n";
                }
            }
        }
    }
    cout << "Number of ways to catch fish: " << number << '\n';
}

int main(void){
    solve();
    return 0;
}