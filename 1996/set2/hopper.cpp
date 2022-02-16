/*
Hoppers are people on a jump stick who can jump from one square to the other, without touching
the squares in between (a bit like a knight in chess). They can pick up speed and make bigger
hops, but their acceleration per move is limited, and they also have a maximum speed. 
The game of Hoppers is played on a rectangular grid, where each square on the grid is either 
empty or occupied. While hoppers can fly over any square, they can only land on empty squares. 
At any point in time, a hopper has a velocity (x,y), where x and y are the speed (in squares) 
parallel to the grid. Thus, a speed of (2,1) corresponds to a knight jump, (as does (-2,1) and 
6 other speeds).

To determine the hops a hopper can make, we need to know how much speed a hopper can pick up or 
lose: either -1, 0, or 1 square in either or both directions. Thus, while having speed (2,1), 
the hopper can change to speeds (1,0), (1,1), (1,2), (2,0), (2,1), (2,2), (3,0), (3,1) and (3,2). 
It is impossible for the hopper to obtain a velocity of 4 in either direction, so the x and y component 
will stay between -3 and 3 inclusive.

The goal of Hoppers is to get from start to finish as quickly as possible (i.e. in the least number of 
hops), without landing on occupied squares. You are to write a program which, given a rectangular grid, 
a start point S, and a finish point F, determines the least number of hops in which you can get from S 
to F. A hopper starts with initial speed (0,0) and does not care about the speed when arriving at F.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


int solve(){
    int n, m, k;
    
    int start[2], end[2];

    cin >> n >> m;

    priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int>>, greater<tuple<int, int, int, int, int>>> pq;
    vector<vector<int>> grid(m, vector<int>(n));
    int velocities[16][16][7][7];
    
    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++){
            for(int i = 0; i < 7; i++){
                for(int j = 0; j < 7; j++){
                    velocities[r][c][i][j] = 0;
                }
            }
        }
    }

    for(int i = 0; i < 2; i++) cin >> start[i];
    for(int i = 0; i < 2; i++) cin >> end[i];

    cin >> k;
    for(int i = 0; i < k; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        for(int r = y1; r <= y2; r++){
            for(int c = x1; c <= x2; c++){
                grid[r][c] = 1;
            }
        }
    }

    pq.emplace(0, start[0], start[1], 0, 0);

    bool found = false;

    while(!pq.empty()){
        tuple<int, int, int, int, int> data = pq.top();
        int l = get<0>(data);
        int x = get<1>(data);
        int y = get<2>(data);
        int dx = get<3>(data);
        int dy = get<4>(data);
        pq.pop();
        if(x == end[0] && y == end[1]){
            cout << "reached in " << l << " steps\n"; 
            found = true;
            break;
        }
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int dx1 = dx + i;
                int dy1 = dy + j;
                if(abs(dx1) > 3) dx1 = 3 * abs(dx1)/dx1;
                if(abs(dy1) > 3) dy1 = 3 * abs(dy1)/dy1;
                int nx = x + dx1;
                int ny = y + dy1;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(!velocities[ny][nx][dy1 + 3][dx1 + 3] && !grid[ny][nx]){
                    velocities[ny][nx][dy1 + 3][dx1 + 3] = 1;
                    pq.emplace(l + 1, nx, ny, dx1, dy1);
                }
            }
        }
    }

    if(!found) cout << "impossible \n";
}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}