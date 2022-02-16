/*

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void solve(){
    vector<string> dest;
    vector<char> dir;
    string d;
    char di;
    cin >> di >> d;
    dest.push_back("HOME");
    
    while(d != "SCHOOL"){
        dir.push_back(di);
        dest.push_back(d);
        cin >> di >> d;
    }

    dir.push_back(di);

    for(int i = dir.size() - 1; i >= 0; i--){
        string direction = dir[i] == 'L' ? "RIGHT" : "LEFT";
        if(i > 0) cout << "Turn " << direction << " onto " << dest[i] << " street.\n";
        else cout << "Turn " << direction << " into your HOME.\n";
    }
}

int main(void){
    solve();
    return 0;
}