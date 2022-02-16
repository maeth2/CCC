/*
Alp the mountain climber is on the northwest corner of a square area of mountainous terrain
and wishes to find a passage to the opposite (southeast) corner. Alp is currently at an
elevation at which oxygen is not needed, but at any higher elevation oxygen is required.
Oxygen, when required, is used at the rate of one unit per horizontal step.

The northwest corner of the terrain is at position (1, 1) and the southeast corner is at
position (n, n), where n is a positive integer read from the input file. The elevation of each
point ( x, y), ( 1 ≤ x, y ≤ n), is an integer read from the input; each elevation occupies a single
line in the input file.

Alp moves in a series of horizontal steps, where each step moves Alp a unit north, a unit
south, a unit east, or a unit west. Alp must remain in the square region and cannot climb or
descend more than 2 units of elevation in a single step. If the elevation at either the
beginning or the end of the step requires oxygen, a unit of oxygen is consumed by Alp
during the step.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using ll = long long;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int solve(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            cin >> grid[r][c];
        }
    }

    int required_elevation = grid[0][0];
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq ;
    vector<vector<int>> searched(n, vector<int>(n));
    pq.emplace(0, 0, 0, grid[0][0]);

    while(!pq.empty()){
        tuple<int, int, int, int> data = pq.top();
        int oxygen = get<0>(data);
        int x = get<1>(data);
        int y = get<2>(data);
        int elevation = get<3>(data);
        if(x == n - 1 && y == n - 1){
            cout << "NEEDS " << oxygen << "\n";
            break;
        }
        pq.pop();



        for(int i = 0; i < 4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
            if(abs(elevation - grid[dy][dx]) > 2) continue;
            if(searched[dy][dx]) continue;
            searched[dy][dx] = 1;
            int o = grid[dy][dx] > o ? oxygen + 1 : oxygen; 
            pq.emplace(o, dx, dy, grid[dy][dx]);
        }
    }

    if(pq.empty()) cout << "CANNOT MAKE THE TRIP\n"; 
}

int main(void){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}