/*

*/
#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    int x = 0, y = 0, dx, dy, c, r;
    cin >> c >> r >> dx >> dy;

    while(dx != 0 || dy != 0){
        int nx = x + dx;
        int ny = y + dy;
        if(nx < 0){
            nx = 0;
        }else if (nx > c){
            nx = c;
        }
        if(ny < 0){
            ny = 0;
        }else if (ny > r){
            ny = r;
        }
        x = nx;
        y = ny;
        cout << x << ' ' << y << "\n";
        cin >> dx >> dy;
    }
}

int main(void){
    solve();
    return 0;
}