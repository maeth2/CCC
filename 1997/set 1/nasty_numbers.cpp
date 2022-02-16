/*
We will call a positive integer "Nasty" if it has at least two pairs of positive integer factors such
that the difference of one pair equals the sum of the other pair.
For example, 6 is nasty since 6 1 6 × = , 2 3 6 × = , and 6 – 1 2 3 = + ;
and 24 is also nasty since 12 – 2 6 4 = + .
Write a program which accepts as input a list of positive integers and determine if each one is
nasty or not.
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> compare;

    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            compare.emplace_back(n / i, i);
        }
    }

    for(int i = 0; i < compare.size(); i++){
        for(int j = i; j < compare.size(); j++){
            if(compare[i].first - compare[i].second == compare[j].first + compare[j].second){
                cout << n << " is nasty\n"; 
                return 1;
            }
        }
    }
    cout << n << " is not nasty\n";
}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}