/*

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

void solve(){
    int f, l, w;
    cin >> f >> l >> w;
    char grid[25][25];
    int searched[25][25];

    for(int r = 0; r < l; r++){
        for(int c = 0; c < w; c++){
            cin >> grid[r][c];
            searched[r][c] = 0;
        }
    }

    vector<int> rooms;
    bool found = true;
    while(found){
        found = false;
        int area = 0;
        queue<pair<int, int>> pq;

        for(int r = 0; r < l && !found; r++){
            for(int c = 0; c < w && !found; c++){
                if(grid[r][c] == '.' && !searched[r][c]){
                    pq.emplace(c, r);
                    searched[r][c] = 1;
                    area++;
                    found = true;
                    break;
                }
            }
        }

        while(!pq.empty()){
            int x = pq.front().first;
            int y = pq.front().second;
            pq.pop();
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if(i == 0 && j == 0) continue;
                    if(i != 0 && j != 0) continue;
                    int nx = x + i;
                    int ny = y + j;
                    if(ny < 0 || ny >= l || nx < 0 || nx >= w) continue;
                    if(searched[ny][nx] || grid[ny][nx] == 'I') continue;
                    pq.emplace(nx, ny);
                    area++;
                    searched[ny][nx] = 1;
                }
            }
        }

        if(found) rooms.push_back(area);
    }

    for(int i = 0; i < rooms.size() - 1; i++){
        for(int j = i; j < rooms.size(); j++){
            if(rooms[i] < rooms[j]) swap(rooms[i], rooms[j]);
        }
    }

    int num = 0;

    for(num = 0; num < rooms.size() && f != 0; num++){
        f -= rooms[num];
        if(f < 0){
            f += rooms[num];
            break;
        }
    }

    cout << num << " room" << (num != 1 ? "s" : "") << ", " << f << " square metre(s) left over\n";
}

int main(void){
    solve();
    return 0;
}