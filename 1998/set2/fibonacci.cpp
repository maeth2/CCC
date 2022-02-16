/*
The nth Fibonacci number, f(n), is defined thus:

f(1) = 1
f(2) = 1
f(n) = f(n-1) + f(n-2) [for all n > 2]

Write a program that reads several n, one per line, and writes the corresponding f(n), one per line. 
Each value of n will be between 1 and 200. The last line of input contains 0.
*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> cache(200);

ll recurse(int n){
    if(n <= 2) return 1;
    if(cache[n] != -1){
        return cache[n];
    }else{
        cache[n] = recurse(n - 1) + recurse(n - 2);
    }
    return cache[n];
}

int solve(int n){
    cout << recurse(n) << "\n";
}

int main(void){
    int t;

    for(int i = 0; i < cache.size(); i++) cache[i] = -1;
    
    while(true){
        cin >> t;
        if(t == 0) break;
        solve(t);
    }

    return 0;
}