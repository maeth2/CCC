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
    int ans = 0;
    vector<char> student(n);
    vector<char> answer(n);
    for(int i = 0; i < n; i++){cin >> student[i];}
    for(int i = 0; i < n; i++){cin >> answer[i];}
    for(int i = 0; i < n; i++){
        if(student[i] == answer[i]){
            ans++;
        }
    }
    cout << ans << "\n";
}

int main(void){
    solve();
    return 0;
}