/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> groups(n);
    map<string, int> dict;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        dict[a] = i;
    }
    for(int i = 0; i < n; i++){
        string b;
        cin >> b;
        int index = dict.at(b);
        groups[i] = index;
    }

    bool found = true;
    for(int i = 0; i < n; i++){
        if(groups[groups[i]] != i || (groups[i] == i)){
            found = false;
            break;
        }
    }

    if(found) cout << "good\n";
    else cout << "bad\n";
}

int main(void){
    solve();
    return 0;
}