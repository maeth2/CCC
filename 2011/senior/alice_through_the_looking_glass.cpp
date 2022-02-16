/*

*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int coords[4][2] = {{0, 2}, {1, 2}, {0, 1}, {0, 3}};

bool recurse(int m, int x, int y, int offx, int offy, int i){
    if(i > m) return false;
    int u = pow(5, m) / pow(5, i);
    for(int j = 0; j < 4; j++){
        if(x >= u * coords[j][1] + offx && x < u * (coords[j][1] + 1) + offx && y >= u * coords[j][0] + offy && y < u * (coords[j][0] + 1) + offy){
            return true;
        }
    }
    for(int j = 1; j < 4; j++){
        if(recurse(m, x, y, u * coords[j][1] + offx, u * (coords[j][0] + 1) + offy, i + 1)) return true;
    }
    return false;
}

void solve(){
    int t;
    cin >> t;
    for(int cases = 0; cases < t; cases++){
        int m, x, y;
        cin >> m >> x >> y;
        if(recurse(m, x, y, 0, 0, 1)){cout << "crystal\n";}
        else{cout << "empty\n";}
    }
}

int main(void){
    solve();
    return 0;
}