/*

*/
#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    int w, h, w1, h1, steps, x, y;
    cin >> w >> h >> w1 >> h1 >> steps;
    int grid[20][20];
    x = w1;
    y = 0;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if((i < h1 || i >= h - h1) && (j < w1 || j >= w - w1)){
                grid[i][j] = 1;
            }else{
                grid[i][j] = 0;
            }
        }
    }

    int dir = 0;
    int top = 0, bot = h - 1, left = 0, right = w - 1;
    while(steps > 0){
        int prevy = y;
        int prevx = x;
        grid[y][x] = 1;
        steps--;
        if(dir == 0){
            if(x + 1 <= right && !grid[y][x + 1]){
                x += 1;
            }else{
                if(!grid[y + 1][x]) y += 1;
            }
            if(x == right){
                top += 1;
                dir++;
            }
        }else if(dir == 1){
            if(y + 1 <= bot && !grid[y + 1][x]){
                y += 1;
            }else{
                if(!grid[y][x - 1]) x -= 1;
            }
            if(y == bot){
                right -= 1;
                dir++;
            }
        }else if(dir == 2){
            if(x - 1 >= left && !grid[y][x - 1]){
                x -= 1;
            }else{
                if(!grid[y - 1][x]) y -= 1;
            }
            if(x == left){
                bot -= 1;
                dir++;
            }
        }else if(dir == 3){
            if(y - 1 >= top && !grid[y - 1][x]){
                y -= 1;
            }else{
                if(!grid[y][x + 1]) x += 1;
            }
            if(y == top){
                left += 1;
                dir = 0;
            }
        }
        if(prevy == y && prevx == x) break;
    }
    cout << x + 1 << '\n' << y + 1 << '\n';
}

int main(void){
    solve();
    return 0;
}