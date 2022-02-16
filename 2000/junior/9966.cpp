/*
The digits 0, 1, and 8 look much the same if rotated 180 degrees on the page (turned
upside down). Also, the digit 6 looks much like a 9, and vice versa, when rotated 180
degrees on the page. A multi-digit number may also look like itself when rotated on the
page; for example 9966 and 10801 do, but 999 and 1234 do not.
*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve(){
    int a, b, ans = 0;
    //cout << "Enter the lower bound of the interval:\n";
    cin >> a;
    //cout << "Enter the upper bound of the interval:\n";
    cin >> b;
    for(int i = a; i <= b; i++){
        int x = i;
        vector<int> num;
        while(x != 0){
            int a1 = x % 10;
            num.push_back(a1);
            x -= a1;
            x /= 10;
        }
        int s = num.size();
        for(int j = 0; j <= s; j++){
            if(j == s){
                ans++;
                break;
            }
            if((num[j] == 0 && num[s - 1 - j] == 0) || 
            (num[j] == 1 && num[s - 1 - j] == 1) || 
            (num[j] == 8 && num[s - 1 - j] == 8) || 
            (num[j] == 9 && num[s - 1 - j] == 6) || 
            (num[j] == 6 && num[s - 1 - j] == 9)) continue;
            break;
        }
    }
    cout << ans;
    //cout << "The number of rotatable numbers is:\n" << ans;
}

int main(void){
    solve();
    return 0;
}