/*

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

long inm[14] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
void solve(){
    vector<long> motels;
    for(long i = 0; i < 14; i++){
        motels.push_back(inm[i]);
    }
    long a, b;
    cin >> a >> b;
    long n;
    cin >> n;
    for(long i = 0; i < n; i++){
        long d;
        cin >> d;
        motels.push_back(d);
    }

    sort(motels.begin(), motels.end());

    vector<long> routes(motels.size());

    routes[0] = 1;
    for(long i = 1; i < motels.size(); i++){
        for(long j = 0; j < i; j++){
            long dist = motels[i] - motels[j];
            if(dist <= b && dist >= a){
                routes[i] += routes[j];
            }
        }
    }
    cout << routes[routes.size() - 1] << "\n";
}

int main(void){
    solve();
    return 0;
}