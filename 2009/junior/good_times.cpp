/*

*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;

double diff[6] = {-300, -200, -100, 0, 100, 130};
string dest[6] = {"Victoria", "Edmonton", "Winnipeg", "Toronto", "Halifax", "St. John's"};

void solve(){
    int time;
    cin >> time;
    cout << time << " in Ottawa\n";

    for(int i = 0; i < 6; i++){
        int nt = time + diff[i];
        if(nt > 2400){
            nt = nt - 2400;
        }else if(nt < 0){
            nt = nt + 2400;
        }
        if(nt % 100 > 60){
            nt = (nt / 100 * 100 + 100) + (nt % 100 - 60);
        }
        cout << nt << " in " << dest[i] << "\n";
    }
}

int main(void){
    solve();
    return 0;
}