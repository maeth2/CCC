/*

*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int l, w, x;

void recurse(int l, int c, int ori, int x, int y, int x2, int y2, vector<vector<char>> &grid, bool d){
    int length;

    int dirx = 1, diry = 1, dx = 1, dy = 0;

    if(c == l) return;
    
    if(ori == 0 || ori == 1){
        length = (abs(x2 - x) + 1) / 3;
        if(ori == 1) diry = -1;
        dx = 1;
        dy = 0;
    }else{
        length = (abs(y2 - y) + 1) / 3;
        if(ori == 3) dirx = -1;
        dx = 0;
        dy = 1;
    }

    int minx = x < x2 ? x : x2;
    int miny = y < y2 ? y : y2;

    int mx = minx;
    int my = miny;

    if(ori < 2) miny += diry;
    else minx += dirx;
    
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            int nx = j * dirx + minx + length * dx;
            int ny = i * diry + miny + length * dy;
            if(nx < 0 || nx >= w || ny < 0 || ny >= w) continue;
            grid[ny][nx] = '*';
        }
    }

    int sec1[2][2] = {{mx, mx + (length - 1) * dx}, {my, my + (length - 1) * dy}};
    int sec2[2][2] = {{minx + length * dx, minx + (length * 2 - 1) * dx}, {miny + length * dy, miny + (length * 2 - 1) * dy}};
    int sec3[2][2] = {{mx + length * 2 * dx , mx + (length * 3 - 1) * dx}, {my + length * 2 * dy, my + (length * 3 - 1) * dy}};
         
    recurse(l, c + 1, ori, sec1[0][0], sec1[1][0], sec1[0][1], sec1[1][1], grid, true);
    recurse(l, c + 1, ori, sec3[0][0], sec3[1][0], sec3[0][1], sec3[1][1], grid, true);

    recurse(l, c + 1, ori, sec2[0][0] + dirx * (length - 1) * dy, sec2[1][0] + diry * (length - 1) * dx, sec2[0][1] + dirx * (length - 1) * dy, sec2[1][1] + diry * (length - 1) * dx, grid, false);
    recurse(l, c + 1, (ori < 2 ? 3 : 1), sec2[0][0], sec2[1][0], sec2[0][0] + dirx * (length - 1) * dy, sec2[1][0] + diry * (length - 1) * dx, grid, false);
    recurse(l, c + 1, (ori < 2 ? 2 : 0), sec2[0][1], sec2[1][1], sec2[0][1] + dirx * (length - 1) * dy, sec2[1][1] + diry * (length - 1) * dx, grid, false);
}

void solve(){
    cin >> l >> w >> x;
    vector<vector<char>> grid(w, vector<char>(w));
    int ans[81];
    for(int i = 0; i < w; i++){
        for(int j = 0; j < w; j++){
            grid[i][j] = ' ';
        }
    }
    for(int i = 0; i < w; i++) ans[i] = 0;
    for(int i = 0; i < w; i++){
        grid[0][i] = '*';
    }
    recurse(l, 0, 0, 0, 0, w, 0, grid, false);
    for(int i = 1; i < w; i++){
        if(grid[i][x] == ' '){
            if(grid[i][x - 1] == '*'){
                ans[i] = 1;
                ans[i + 1] = 1;
            }else if(grid[i - 1][x] == '*'){
                ans[i] = 1;
            }
        }else if(grid[i][x - 1] == ' '){
            ans[i] = 1;
            ans[i + 1] = 1;
        }

    }
    for(int i = 0; i < w; i++){
        if(ans[i]) cout << i << ' ';
    }
    cout << "\n";
}

int main(void){
    solve();
    return 0;
}