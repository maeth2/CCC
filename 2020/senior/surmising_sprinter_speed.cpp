/*

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<pair<double, double>> times;
    for(int i = 0; i < n; i++){
        double t, x;
        cin >> t >> x;
        times.emplace_back(t, x);
    }
    sort(times.begin(), times.end());
    double prevtime = -1; double prevpos = 0;
    double mx = -1;
    for(pair<int, int> i : times){
        if(prevtime < 0){
            prevtime = i.first;
            prevpos = i.second;
            continue;
        }
        double time = abs(i.first - prevtime);
        double displacement = abs(i.second - prevpos);
        prevtime = i.first;
        prevpos = i.second;
        mx = max(displacement / time, mx);
    }
    cout << mx << '\n';
}

int main(void){
    solve();
    return 0;
}