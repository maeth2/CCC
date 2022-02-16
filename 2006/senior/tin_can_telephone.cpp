/*

*/
#include <iostream>

using namespace std;
using ll = long long;
float m1, b1, xr, yr, xj, yj;

bool checkFallOnLine(float a, float a1, float a2){
    return (a <= a1 && a >= a2) || (a <= a2 && a >= a1);
}

bool checkLine(float x1, float x2, float y1, float y2){
    bool vertical = x1 - x2 == 0;
    float m, b;
    if(vertical){
        m = INT16_MAX;
        b = INT16_MAX;
    }else{
        m = (y2 - y1) / (x2 - x1);
        b = y1 - x1 * m;
    }
    if(m == m1){
        if(m != INT16_MAX){
            if(b == b1){
                return checkFallOnLine(x1, xr, xj) || checkFallOnLine(x2, xr, xj);       
            }
        }else if(x1 == xr){
            return checkFallOnLine(y1, yr, yj) || checkFallOnLine(y2, yr, yj);
        }
    }else{
        float px, py;
        if(m1 == INT16_MAX){
            px = xr;
            py = m * px + b;
        }else if(m == INT16_MAX){
            px = x1;
            py = m1 * px + b1;
        }else{
            px = (b - b1) / (m1 - m);
            py = m * px + b;
        }
        return checkFallOnLine(px, xr, xj) && checkFallOnLine(py, yr, yj) && checkFallOnLine(px, x1, x2) && checkFallOnLine(py, y1, y2);
    }
    return false;
}

void solve(){
    cin >> xr >> yr >> xj >> yj;
    bool vertical = xr - xj == 0;
    if(!vertical){
        m1 = (yj - yr) / (xj - xr);
        b1 = yj - xj * m1;
    }else{
        m1 = INT16_MAX;
        b1 = INT16_MAX;
    }
    int n, ans = 0;
    cin >> n;
    for(int num = 0; num < n; num++){
        int c;
        cin >> c;
        int x1, y1, x2, y2;
        bool first = true;
        bool found = false;
        for(int corners = 0; corners < c; corners++){
            if(first){
                cin >> x1 >> y1;
                first = false;
                continue;
            }
            cin >> x2 >> y2;
            if(!found && checkLine(x1, x2, y1, y2)){
                ans++;
                found = true;
            }
            x1 = x2;
            y1 = y2;
        }
    }
    cout << ans;
}

int main(void){
    solve();
    return 0;
}