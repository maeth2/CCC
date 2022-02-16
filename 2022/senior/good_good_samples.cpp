/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int mx_sample = n;

    for(int i = 1; i < m; i++){
        mx_sample += (n - i);
    }   


    if(k > mx_sample || k < n){
        cout << "-1\n";
        return;
    }

    vector<int> a;

    mx_sample = n;
    int ones = n;
    int add = 1;

    while(mx_sample < k){
        mx_sample += add;
        add++;
        ones--;
        if(add >= m) add = m - 1;
    }

    for(int i = 0; i < ones; i++){
        a.push_back(1);
    }

    int j = 2;
    for(int i = ones; i < n; i++){
        if(j != 1) a.push_back(j);
        j++;
        if(j > m) j = 1;
    }

    int diff = mx_sample - k;
    int ms = min(n - ones, m);
    int gap = ones + ms - diff;
    if(ms == m) gap--;

    while(gap < n){
        a.insert(a.begin() + gap, 1);
        gap += ms;
    }
    while(a.size() > n){
        a.pop_back();
    }

    for(int i : a){
        cout << i << ' ';
    }
    cout << "\n"; 
}

int main(void){
    solve();
    return 0;
}