/*
In a primitive video game, a spot bounces around within a rectangular grid. The southwest corner of the grid has coordinates 
(0,0) and the northeast corner has coordinates (r,c) where 0 < r <= 10 and 0 < c <= 10. The southeast corner has coordinates 
(0,c) and the northwest corner has coordinates (r,0). The spot always travels on the diagonal; that is, in one of the directions 
NE, NW, SE, SW. The outer edges of the grid serve as mirrors: after visiting a position on the edge of the grid the spot "bounces" 
off according to the normal rules of reflection (Snell's Law). For example, if the spot were travelling NE and hit the east edge of 
the grid, it would change direction to NW. If the spot were to hit the corner of the grid it would change to the opposite direction.

Given a grid size, two points A and B lying on the grid, and an initial direction, you are to determine if the spot moves from A to B 
and, if so, how far the spot moves (in terms of number of grid positions) before reaching B the first time.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int solve(){
    int r, c, ar, ac, br, bc;
    string d;
    cin >> r >> c >> ar >> ac >> br >> bc >> d;
    int dr, dc;

    dr = d[0] == 'N' ? 1 : -1;
    dc = d[1] == 'E' ? 1 : -1;
    
    int pos[2] = {ar, ac};
    int idr = dr, idc = dc;
    int moves = 0;
    bool complete = true;
    while(pos[0] != br || pos[1] != bc){
        if(pos[0] == r) dr = -1;
        if(pos[1] == c) dc = -1;
        if(pos[0] == 0) dr = 1;
        if(pos[1] == 0) dc = 1;

        if(moves != 0 && pos[0] == ar && pos[1] == ac && idr == dr && idc == dc){
            complete = false;
            break;
        }

        pos[0] += dr;
        pos[1] += dc;

        if(pos[0] == ar && pos[1] == ac && idr == dr && idc == dc){
            complete = false;
            break;
        }
        moves++;
    }

    if(!complete){
        cout << "B cannot be reached from A\n";
    }else{
        cout << "B can be reached from A after " << moves << " moves\n";
    }
}

int main(void){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}