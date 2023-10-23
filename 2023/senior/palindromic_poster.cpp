/*
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int n, m, R, C;
    cin >> n >> m >> R >> C;
    vector<vector<char>> grid(n, vector<char>(m, 'b'));
    if(R != n && C != m && R != 0 && C != 0){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] = 'a';
            }
        }
        for(int i = 0; i < C; i++){
            for(int j = 0; j < n; j++){
                grid[j][i] = 'a';
            }
        }
    }else if(R == 0 && C != 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m - 1; j++){
                grid[i][j] = 'a';
            }
        }
        for(int i = 0; i < C; i++){
            grid[n - 1][m - 1 - i]++;
        }
    }else if(R != 0 && C == 0){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n - 1; j++){
                grid[j][i] = 'a';
            }
        }
        for(int i = 0; i < R; i++){
            grid[n - 1 - i][m - 1]++;
        }
    }else if(R == n && C != m){
        if((m - C) % 2 != 0){
            cout << "IMPOSSIBLE\n";
            return;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] = 'a';
            }
        }
        for(int i = 0; i < C / 2; i++){
            grid[0][i]++;
            grid[0][m - i - 1]++;
        }
    }else if(R != n && C == m){
        if((n - R) % 2 != 0){
            cout << "IMPOSSIBLE\n";
            return;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] = 'a';
            }
        }
        for(int i = 0; i < R / 2; i++){
            grid[i][0]++;
            grid[n - i - 1][0]++;
        }
    }
    
    for(vector<char> i : grid){
        for(char j : i){
            cout << j << ' ';
        }
        cout << "\n";
    }
}

int main(void){
    solve();
    return 0;
}