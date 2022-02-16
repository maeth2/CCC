/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int r[1000];
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        r[a]++;
    }
    vector<int> mx;
    int mxn = -1;
    int diff = -1;
    for(int i = 0; i < 1000; i++){
        if(r[i] > mxn){
            mx.clear();
            mx.push_back(i);
            diff = -1;
            mxn = r[i];        
        }else if(r[i] == mxn){
            mx.push_back(i);
            for(int j : mx){
                if(abs(j - i) > diff){
                    diff = abs(j - i);
                }
            }
        }
    }
    if(mx.size() == 1){
        int mxn2 = -1;
        diff = -1;
        for(int i = 0; i < 1000; i++){
            if(r[i] == mxn) continue;
            if(r[i] > mxn2){
                mxn2 = r[i];
                diff = abs(i - mx[0]);
            }else if(r[i] == mxn2){
                diff = max(abs(i - mx[0]), diff);
            }
        }
    }
    cout << diff << "\n";
}

int main(void){
    solve();
    return 0;
}