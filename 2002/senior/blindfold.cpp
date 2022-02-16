/*

*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

char grid[375][80];
int l, w, m;
int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

void solve(){
    cin >> l >> w;
    for(int r = 0; r < l; r++){
        for(int c = 0; c < w; c++){
            cin >> grid[r][c];
        }
    }

    
    int d = 0;

    cin >> m;

    vector<int> steps;

    for(int i = 0; i < m; i++){
        char c;
        cin >> c; 
        if(c == 'F'){
            steps.push_back(d);
        }else if(c == 'R'){
            d++;
            if(d > 3) d = 0;
        }else if(c == 'L'){
            d--;
            if(d < 0) d = 3;
        }
    }

    for(int r = 0; r < l; r++){
        for(int c = 0; c < w; c++){
            if(grid[r][c] == 'X') continue;
            for(int i = 0; i < 4; i++){
                int nr = r;
                int nc = c;
                for(int j = 0; j < steps.size(); j++){
                    int nd = steps[j] + i; 
                    if(nd > 3) nd = nd - 4;
                    else if (nd < 0) nd = 0 - nd;
                    nc = nc + dir[nd][0];
                    nr = nr + dir[nd][1];
                    if(nc < 0 || nc >= w || nr < 0 || nr >= l) break;
                    if(grid[nr][nc] == 'X') break;
                    if(j == steps.size() - 1){
                        grid[nr][nc] = '*';
                    }
                }
            }
        }
    }
    for(int r = 0; r < l; r++){
        for(int c = 0; c < w; c++){
            cout << grid[r][c];
        }
        cout << "\n";
    }
}

int main(void){
    solve();
}