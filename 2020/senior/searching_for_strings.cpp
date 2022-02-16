/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
using ll = long long;

string n, h;

int total = 0;

vector<int> ac(26);
vector<int> bc(26);

bool check(){
    for(int i = 0; i < 26; i++){
        if(bc[i] != ac[i]) return false;
    }
    return true;
}

void solve(){
    cin >> n >> h;
    if(n.size() > h.size()){
        cout << 0 << '\n';
        return;
    }
    for(char c : n){
        ac[c - 'a']++;
    }
    int index = 0;
    string b = "";
    for(int i = 0; i < h.size(); i++){
        bc[h[i] - 'a']++;
        if(i < n.size() - 1) continue;
        if(i > n.size() - 1) bc[h[i - n.size()] - 'a']--;
        for(int j : bc){
            cout << j << ' ';
        }
        cout << '\n';

    }
    cout << total << '\n';
}

int main(void){
    solve();
    return 0;
}