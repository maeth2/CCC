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
    int max = -1;
    int max2 = -1;
    string ms = "";
    string ms2 = "";
    for(int i = 0; i < n; i++){
        string name;
        int r, s, d;
        cin >> name >> r >> s >> d;
        int j =  2 * r + 3 * s + d;
        if(j > max || (j == max && name.size() < ms.size())){
            max2 = max;
            max = j;
            ms2 = ms;
            ms = name;
        }else if(j > max2 || (j == max2 && name.size() < ms2.size())){
            max2 = j;
            ms2 = name;
        }
    }

    if(n == 1){
        cout << ms << '\n';
    }else{
        cout << ms << '\n' << ms2 << '\n';
    }
}

int main(void){
    solve();
    return 0;
}