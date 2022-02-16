/*

*/
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using ll = long long;

int dir[4][2] = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};

void solve(){
    int row, col;
    cin >> row >> col;
    char grid[20][20];
    bool searched[20][20];
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            cin >> grid[r][c];
            searched[r][c] = false;
        }
    }
    int ans = -1;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.emplace(0, 0, 0);
    while(!pq.empty()){
        int d = get<0>(pq.top());
        int r = get<1>(pq.top());
        int c = get<2>(pq.top());
        pq.pop(); 
        char cd = grid[r][c];
        if(searched[r][c]) continue;
        searched[r][c] = true;
        if(cd == '*') continue;
        if(r == row - 1 && c == col - 1){
            ans = d + 1;
            break;
        }
        int sr, se;
        if(cd == '+'){
            sr = 0;
            se = 4;
        }else if(cd == '|'){
            sr = 2;
            se = 4;
        }else if(cd == '-'){
            sr = 0;
            se = 2;
        }
        for(int i = sr; i < se; i++){
            int nr, nc;
            nr = r + dir[i][0];
            nc = c + dir[i][1];
            if(nr >= row || nr < 0 || nc >= col || nc < 0) continue;
            if(searched[nr][nc]) continue;
            pq.emplace(d + 1, nr, nc);
        }
    }
    cout << ans << "\n";
}

int main(void){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
    return 0;
}