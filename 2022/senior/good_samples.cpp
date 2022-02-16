/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
int n, m, k;

int check(vector<int> array){
    int total = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n - i; j++){
            vector<bool> searched(1000000);
            bool found = false;
            for(int z = j; z < j + i; z++){
                if(searched[array[z]]){
                    found = true;
                    break;
                }
                searched[array[z]] = true;
            }
            if(!found){
                total++;
            }
        }
    }
    return total;
}

int recurse(vector<int> array){
    if(array.size() == n){
        if(check(array) == k){
            for(int i : array){
                cout << i + 1 << ' ';
            }
            cout << " = " << k << '\n';
            return 1;
        }
        else return -1;
    }
    for(int i = 0; i < m; i++){
        vector<int> ar = array;
        ar.push_back(i);
        int t = recurse(ar);
        if(t > 0) return t;
    }
    return -1;
}
void solve(){
    n = 8;
    for(m = 1; m < 10; m++){
        cout << n << ' ' << m << '\n';
        for(k = n; k < 40; k++){
            vector<int> array;
            recurse(array);
        }
        cout << '\n';
    }
}

int main(void){
    solve();
    return 0;
}