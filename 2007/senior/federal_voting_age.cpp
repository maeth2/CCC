/*

*/
#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int year, month, day;
        cin >> year >> month >> day;
        if(2007 - year > 18){
            cout << "Yes\n";
            continue;
        }else if(2007 - year == 18){
            if(month < 2){
                cout << "Yes\n";
                continue;
            }else if(month == 2){
                if(day <= 27){
                    cout << "Yes\n";
                    continue; 
                }
            }
        }
        cout << "No\n";
    }
}

int main(void){
    solve();
    return 0;
}