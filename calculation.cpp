/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

#define g 9.8
#define PI 3.14159265

using namespace std;
using ll = long long;


void solve(){
    float h, e, e1, v, vh, vv, t, d;
    float k, x, zl, angle, m;
    cin >> k >> x >> zl >> angle >> m;
    x /= 100;
    zl /= 100;
    m /= 1000;
    angle = angle * PI/180;
    h = sin(angle);
    e = 0.5 * k * (x - zl) * (x - zl) + m * g * h; 
    v = sqrt((2 * (e - m * g * h)) / m);
    vh = cos(angle) * v;
    vv = sin(angle) * v;
    t = (vv + sqrt(vv * vv - 4 * g/2 * -h))/ (g);
    d = vh * t;
    cout << d << '\n';
    float actual, error;
    cin >> actual;
    actual /= 100;
    error = abs(actual - d) / d * 100;
    cout << error << "%\n"; 
}

int main(void){
    solve();
    return 0;
}