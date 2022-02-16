/*

*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

void solve(){
    int x[10];
    int y[10];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    float ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                //Heron's formula Area = sqrt(s * (s - a) * (s - b) * (s - c))
                float d = 0;
                float a = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                float b = sqrt((x[i] - x[k]) * (x[i] - x[k]) + (y[i] - y[k]) * (y[i] - y[k]));
                float c = sqrt((x[k] - x[j]) * (x[k] - x[j]) + (y[k] - y[j]) * (y[k] - y[j]));
                float s = (a + b + c) / 2;
                if(s == 0 || (a * a + b * b - c * c) < 0 || (a * a + c * c - b * b) < 0 || (c * c + b * b - a * a) < 0){
                    if(a > d){
                        d = a;
                    }
                    if(b > d){
                        d = b;
                    }
                    if(c > d){
                        d = c;
                    }
                }else{
                    //Circle radius surcumsizing triangle Radius = (abc) / (4 * Area)
                    d = 2 * (a * b * c) / (4 * sqrt(s * (s - a) * (s - b) * (s  -c)));
                }
                if(d > 0){
                    ans = d;
                }   
            }
        }
    }
    cout << fixed << setprecision(2) << ans << "\n";
}

int main(void){
    solve();
    return 0;
}