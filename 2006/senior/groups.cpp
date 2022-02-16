/*

*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

bool solve(int size){
    vector<vector<int>> grid (size, vector<int>(size));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cin >> grid[i][j];
        }
    }

    int identity = -1;
    for(int i = 0; i < size; i++){
        bool found = true;
        for(int j = 0; j < size; j++){
            if(grid[i][j] != j + 1 || grid[j][i] != j + 1){
                found = false;
                break;
            }
        }
        if(found){
            identity = i + 1;
            break;
        }
    }

    if(identity == -1) return false;

    bool inverse = true;
    for(int i = 0; i < size; i++){
        bool found = false;
        for(int j = 0; j < size; j++){
            if(grid[i][j] == identity && grid[j][i] == identity){
                found = true;
                break;
            }
        }
        if(!found){
            inverse = false;
            break;
        }
    }

    if(!inverse) return false;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int z = 0; z < size; z++){
                if(grid[i][grid[j][z] - 1] != grid[grid[i][j] - 1][z]){
                    // cout << i << ' ' << j << ' ' << z << '\n';
                    // cout << grid[i][grid[j][z] - 1] << ' ' << grid[grid[i][j] - 1][z] << '\n';
                    return false;
                }
            }
        }
    }

    return true;
}
 
int main(void){
    int size;
    while(true){
        cin >> size;
        if(size == 0) break;
        if(solve(size)){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    } 
    return 0;
}