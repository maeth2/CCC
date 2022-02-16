/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;

vector<vector<pair<int, int>>> together(400000);
vector<vector<pair<int, int>>> apart(400000);
vector<bool> rule(200000);
map<string, int> dict;

int inx = 0;

int add_name(string a){
    if(dict.find(a) == dict.end()){
        dict[a] = inx;
        inx++;
        return inx - 1;
    }
    return dict[a];
}

int check_apart(string a, string b, string c){
    int violations = 0;
    int a1 = add_name(a);
    int b1 = add_name(b);
    int c1 = add_name(c);
    for(int i = 0; i < apart[a1].size(); i++){
        int t = apart[a1][i].first;
        int rn = apart[a1][i].second;
        if(t == b1 || t == c1){
            if(!rule[rn]){
                rule[rn] = true;
                violations++;
            }
        }

    }
    return violations;
}

int check_together(string a, string b, string c){
    int violations = 0;
    int a1 = add_name(a);
    int b1 = add_name(b);
    int c1 = add_name(c);
    for(int i = 0; i < together[a1].size(); i++){
        int t = together[a1][i].first;
        int rn = together[a1][i].second;
        if(t != b1 && t != c1){
            if(!rule[rn]){
                rule[rn] = true;
                violations++;
            }
        }
    }

    return violations;
}

void solve(){
    int x;
    int y;
    int g;
    string a;
    string b;
    string c;
    int total = 0;
    cin >> x;
    int rn = 0;
    for(int i = 0; i < x; i++){
        cin >> a >> b;
        int a1 = add_name(a);
        int b1 = add_name(b);
        together[a1].emplace_back(b1, rn);
        together[b1].emplace_back(a1, rn);
        rn++;   
    }
    cin >> y;
    for(int i = 0; i < y; i++){
        cin >> a >> b;
        int a1 = add_name(a);
        int b1 = add_name(b);
        apart[a1].emplace_back(b1, rn);
        apart[b1].emplace_back(a1, rn);  
        rn++;
    }
    cin >> g;

    for(int i = 0; i < g; i++){
        cin >> a >> b >> c;
        total += check_apart(a, b, c);
        total += check_apart(b, a, c);
        total += check_apart(c, a, b);
        total += check_together(a, b, c);
        total += check_together(b, a, c);
        total += check_together(c, a, b);
    }
    
    cout << total << '\n';
}

int main(void){
    solve();
    return 0;
}