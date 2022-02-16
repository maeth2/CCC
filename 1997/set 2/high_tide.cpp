/*
A planet has n moons revolving about it in constant clockwise coplanar circular orbits. 
How often do all the moons appear directly overhead as viewed from some point on the 
planet? We will call such a situation a 'vertical alignment'.

Your input consists of a number of sets of lines; each set consists of an integer n, 
indicating the number of moons, followed by n distinct positive integers, one per line, 
indicating the exact period of revolution for each moon, in days. (Thus there are n+1 
lines of data for each set with the first line containing n.) The last line contains only 
a zero.

For each input set, except the last, generate a line of output indicating the interval 
in days, to two decimal places, between consecutive vertical alignments.
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
using ll = long long;

int MIN(int a, int b){return (a > b ? b : a);}

float round_float(float var){
    if(var == 0) return var;
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

bool has_common_factor(vector<int> a){
    vector<vector<int>> factors;
    for(int i = 0; i < a.size(); i++){
        vector<int> r;
        factors.push_back(r);
        for(int j = 1; j < sqrt(a[i]); j++){
            if(a[i] % j == 0){
                factors[i].push_back(j);
                factors[i].push_back(a[i]/j);
            }
        }
    }
}
int solve(int n){
    vector<float> revolutions;
    float min = INT16_MAX;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        min = MIN(min, a);
        revolutions.push_back(a);
    }

    cout << min << "\n";

    bool aligned = false;
    while(!aligned){
        aligned = true;
        float angle = -1;
        for(int i = 0; i < n; i++){
            float ca = min / revolutions[i];
            ca = round_float(fmod(ca, 1));
            if(angle == -1){
                angle = ca;
                continue;
            }
            if(fabs(ca - angle) != 0){
                aligned = false;
                break;
            }
        }
        min += 0.01;
        if(!aligned) continue;
    }
    cout << round_float(min) << "\n";
}

int main(void){
    cout << "round" << round_float(0.3333) << "\n";
    while(true){
        int a;
        cin >> a;
        if(a == 0){break;}

        solve(a);
    }

    return 0;
}