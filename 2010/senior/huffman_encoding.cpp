/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<string> codes;
vector<char> alphabets;

void solve(){
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        char m;
        string c;
        cin >> m >> c;
        codes.push_back(c);
        alphabets.push_back(m);
    }
    
    string code;
    cin >> code;
    while(!code.empty()){
        bool found = false;
        for(int i = 0; i < codes.size(); i++){
            string a = codes[i];
            if(a == code.substr(0, a.size())){
                cout << alphabets[i];
                code = code.substr(a.size(), code.size() - a.size());
                found = true;
                break;
            }
        }
        if(!found) break;
    }
    cout << "\n";
}

int main(void){
    solve();
    return 0;
}