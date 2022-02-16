/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

bool compare(string a, string b){
    if(a.size() < b.size()){
        if(a == b.substr(0, a.size())) return true;
        if(a == b.substr(b.size() - a.size(), a.size())) return true;
    }else{
        if(b == a.substr(0, b.size())) return true;
        if(b == a.substr(a.size() - b.size(), b.size())) return true;
    }
    return false;
}
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        if(compare(s1, s2) || compare(s1, s3) || compare(s2, s3)) cout << "No\n";
        else cout << "Yes\n";
    }   
}

int main(void){
    solve();
    return 0;
}