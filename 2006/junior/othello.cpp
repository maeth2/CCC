/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

char grid[8][8];

void place(string id){
    char sym = 'X';
    for(int i = 1; i < id.size(); i++){
        if(id[i] == 'W'){
            sym = 'O';
            continue;
        }
        int x = id[i] - '0';
        int y = id[i+1] - '0';
        grid[y - 1][x - 1] = sym;
        i += 1;
    }
}

void fill(int x, int y, int x1, int y1, char s){
    int slopex = x - x1;
    int slopey = y - y1;
    slopex = slopex < 0 ? -1 : slopex == 0 ? 0 : 1;
    slopey = slopey < 0 ? -1 : slopey == 0 ? 0 : 1;
    int sx = x1;
    int sy = y1;
    for(int i = 0; i < 8; i++){
        sx += slopex;
        sy += slopey;
        if(sx == x && slopex != 0) break;
        if(sy == y && slopey != 0) break;
        grid[sy][sx] = s;
    }
}

void checkWin(int r, int c, char s){
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0) continue;
            int x1 = c;
            int y1 = r;
            int x = c;
            int y = r;
            for(int k = 1; k < 8; k++){
                x += j;
                y += i;
                if(x < 0 || x > 7 || y < 0 || y > 7) break;
                if(grid[y][x] != 'X' && grid[y][x] != 'O') break;
                if(grid[y][x] == s){
                    fill(x, y, x1, y1, s);
                    x1 = x;
                    y1 = y;
                }
            }
        }
    }
}

void solve(){
    string a = "B5445W4455";
    string b = "B1122334455667788W8172635445362718";
    string c = "B31323334353637384142434445464748W51525354555657586162636465666768";
    int z = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            char s = '*';
            if(z % 2 == 0) s = '.';
            grid[i][j] = s;
            z++;
        }
        z++;
    }
    char t; 
    int n;
    cin >> t >> n;
    if(t == 'a') place(a);
    else if(t == 'b') place(b);
    else if(t == 'c') place(c);

    int turn = 0;

    for(int i = 0; i < n; i++){
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        if(turn % 2 == 0){
            grid[r][c] = 'X';
            checkWin(r, c, 'X');
        }else{
            grid[r][c] = 'O';
            checkWin(r, c, 'O');
        }
        bool changed = true;
        turn++;
    }

    int ans[2] = {0,0};
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(grid[i][j] == 'X') ans[0] ++;
            if(grid[i][j] == 'O') ans[1] ++;
        }
    }

    cout << ans[0] << ' ' << ans[1] << '\n';
}

int main(void){
    solve();
    return 0;
}