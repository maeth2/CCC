/*

*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> points(n);
    while(true){
        int x, y;
        cin >> x >> y;
        if(x == 0 && y == 0) break;
        points[y - 1].push_back(x - 1);
    }

    vector<int> routes(n);
    routes[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j : points[i]){
            routes[i] += routes[j];
        }
    }
    cout << routes[n-1];
}

int main(void){
    solve();
    return 0;
}