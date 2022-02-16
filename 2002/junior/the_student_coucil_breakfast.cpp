/*

*/
#include <iostream>

using namespace std;
using ll = long long;

int min(int a, int b){return a < b ? a : b;}
void solve(){
    int p, g, r, o, t;
    cin >> p >> g >> r >> o >> t;
    int total = 0, min_num = INT16_MAX;
    for(int i = 0; i <= t; i++){
        for(int j = 0; j <= t; j++){
            for(int k = 0; k <= t; k++){
                for(int z = 0; z <= t; z++){
                    int sum = o * z + r * k + g * j + p * i;
                    if(sum == t){
                        cout << "# of PINK is " << i << " # of GREEN is " << j << " # of RED is " << k << " # of ORANGE is " << z << "\n";
                        min_num = min(min_num, z + k + j + i);
                        total++;
                    }
                    if(sum > t) break;
                    if(sum < t) continue;
                }
            }
        }
    }
    cout << "Total combinations is " << total << ".\n";
    cout << "Minimum number of tickets to print is " << min_num << ".\n";
}

int main(void){
    solve();

    return 0;
}