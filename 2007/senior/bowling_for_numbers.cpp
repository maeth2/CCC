/*

*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int max(int a, int b){return a > b ? a : b;}

void solve(){
    long n, k, w;
    cin >> n >> k >> w;
    vector<long> pins;
    for(long i = 0; i < n; i++){
        long p;
        cin >> p;
        pins.push_back(p);
    }

    vector<int> sums(n);
    for(int i = 0; i < n; i++){
        for(int j = i; j < i + w; j++){
            if(j >= n) continue;
            sums[i] += pins[j];
        }
    }

    vector<vector<int>> dp(k + 1, vector<int>(n));
    for(int i = 1; i < k + 1; i++){
        for(int j = n - 1; j >= 0; j--){
            if(j + w >= n) dp[i][j] = sums[j];
            else{
                dp[i][j] = max(dp[i][j + 1], dp[i - 1][j + w] + sums[j]);
            }
        }
    }

    cout << dp[k][0] << "\n";
}

int main(void){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
    return 0;
}