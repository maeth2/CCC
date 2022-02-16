/*

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<vector<string>> posts(2);
vector<int> path;
int n, m, k;
string aaa = "", bbb = "";

int recurse(int abegin, int bbegin, int aend, int bend, int kk){
    if(kk > 0 && abegin == aend && bbegin == bend){
        k = kk;
        for(int i = 0; i < k; i++) path.push_back(0);
        return 1;
    }
    if(abegin != aend && bbegin != bend){
        return 0;
    }
    if(kk == m - 1){
        return 0;
    }
    for(int i = 0; i < n; i++){
        aaa = aaa.substr(0, aend) + posts[0][i];
        bbb = bbb.substr(0, bend) + posts[1][i];
        int a2 = abegin;
        int b2 = bbegin;
        int ae2 = aaa.size();
        int be2 = bbb.size();
        while(a2 < ae2 && b2 < be2 && aaa[a2] == bbb[b2]){
            a2++;
            b2++;
        }
        if(recurse(a2, b2, ae2, be2, kk + 1)){
            path[kk] = i;
            return 1;
        }
    }
    return 0;
}

void solve(){
    cin >> m >> n;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            string a;
            cin >> a;
            posts[i].push_back(a);
        }
    }

    if(recurse(0,0,0,0,0)){
        cout << k << "\n";
        for(int i = 0; i < k; i++){
            cout << path[i] + 1 << "\n";
        }
    }else{
        cout << "No solution.\n";
    }
}

int main(void){
    solve();
    return 0;
}