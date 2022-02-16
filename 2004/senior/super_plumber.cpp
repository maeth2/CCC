/*

*/
#include <iostream>
#include <queue>
#include <string>

using namespace std;
using ll = long long;

int max(int a, int b){return a > b ? a : b;}

void solve(){
    int m, n;
    cin >> m >> n;
    int grid[100][100];
    int cost[100][100];
    while(m != 0 && n != 0){
        for(int r = 0; r < m; r++){
            string l;
            cin >> l;
            for(int c = 0; c < n; c++){
                cost[r][c] = -1;
                if(l[c] == '.'){
                    grid[r][c] = 0;
                }else if(l[c] == '*'){
                    grid[r][c] = -1;
                }else{
                    grid[r][c] = l[c] - '0';
                }
            }
        }

        cost[m - 1][0] = grid[m - 1][0];
        
        for(int i = m - 2; i >= 0; i--){
            if(grid[i][0] == -1) break;
            cost[i][0] = cost[i + 1][0] + grid[i][0];
        }

        for(int c = 1; c < n; c++){
            for(int r = 0; r < m; r++){
                int x = cost[r][c - 1];
                if(x >= 0){
                    for(int k = r; k < m; k++){
                        if(grid[k][c] == -1){
                            r = m;
                            break;
                        };
                        x += grid[k][c];
                        cost[k][c] = max(cost[k][c], x);
                    }
                }
            }

            for(int r = m - 1; r >= 0; r--){
                int x = cost[r][c - 1];
                if(x >= 0){
                    for(int k = r; k >= 0; k--){
                        if(grid[k][c] == -1){
                            r = -1;
                            break;
                        }
                        x += grid[k][c];    
                        cost[k][c] = max(cost[k][c], x);
                    }
                }
            }
        }
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                cout << cost[r][c] << ' ';
            }
            cout << "\n";
        }

        cout << cost[m - 1][n - 1] << "\n";

        cin >> m >> n;
    }
}

int main(void){
    solve();
    return 0;
}