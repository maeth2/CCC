/*

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

void solve(){
    int r, l;
    cin >> r >> l;
    vector<vector<int>> grid(r, vector<int>(l));
    vector<vector<int>> answers;
    int ans = 0;
    for(int i = r - 1; i >= 0; i--){
        for(int j = 0; j < l; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < r; i++){
        //set the row to on
        vector<vector<int>> cg = grid;
        for(int z = 0; z < l; z++){
            cg[i][z] = 1;
        }

        for(int j = i + 1; j < r; j++){
            for(int z = 0; z < l; z++){
                bool a = cg[j][z];
                bool b = cg[j - 1][z];
                cg[j][z] = (!a && !b) || (a && b) ? 0 : 1;
            }
        }

        bool found = false;
        for(vector<int> a : answers){
            bool f = true;
            for(int j = 0; j < l; j++){
                if(a[j] != cg[r - 1][j]){
                    f = false;
                    break;
                }
            }
            found = f || found;
        }
        if(!found){
            answers.push_back(cg[r - 1]);
            ans++;
        }
    }
    cout << ans << "\n";
}

int main(void){
    solve();
    return 0;
}