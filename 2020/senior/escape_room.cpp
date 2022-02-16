/*

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int m, n;

vector<vector<pair<int, int>>> val(1002001);

bool bfs(int r, int c, vector<vector<bool>> &searched){
    searched[r][c] = true;
    int v = r * c;
    if(r == 1 && c == 1) return true;
    for(pair<int, int> i : val[v]){
        if(searched[i.first][i.second]) continue;
        if(bfs(i.first, i.second, searched)) return true;
    }
    return false;
}

void solve(){
    cin >> m >> n;
    vector<vector<int>> grid(m + 1, vector<int>(n + 1));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int v;
            cin >> v;
            val[v].emplace_back(i, j);
        }
    }
    vector<vector<bool>> searched(m + 1, vector<bool>(n + 1));
    if(bfs(m, n, searched)) cout << "yes\n";
    else cout << "no\n";
}

int main(void){
    solve();
    return 0;
}