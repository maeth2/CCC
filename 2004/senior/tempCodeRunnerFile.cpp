/*

*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

void solve(){
    double sx, sy, sz, tx ,ty, tz, x, y, z, d, c, t;
    cin >> tx >> ty >> tz >> sx >> sy >> sz;
    x = sx - tx;
    y = sy - ty;
    z = sz - tz;
    c = x * x + y * y + z * z;
    char dir;
    cin >> d >> dir;
    while(dir != 'E'){

        double nx = x - d;

        t = x;

        if(nx * x < 0){
            c = min(c, y * y + z * z);
        }else{
            c = min(c, nx * nx + y * y + z * z);
        }

        cout << "dist = " << c << "\n";

        if(dir == 'L'){
            x = y;
            y = -t;
        }else if(dir == 'R'){
            x = -y;
            y = t;
        }else if(dir == 'U'){
            x = z;
            z = -t;
        }else if(dir == 'D'){
            x = -z;
            z = t;
        }
        cin >> d >> dir;
    }
    cout << fixed << setprecision(2) << sqrt(c);
}

int main(void){
    solve();
    return 0;
}