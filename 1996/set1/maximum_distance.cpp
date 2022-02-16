/*
Consider two descending sequences of integers X[0..n-1] and Y[0..n-1] with 
X[i] >= X[i+1] and Y[i] >= Y[i+1] and for all i, 0 <= i < n - 1. The distance 
between two elements X[i] and Y[j] is given by

d(X[i], Y[j]) = j - i if j >= i and Y[j] >= X[i], or 0 otherwise
The distance between sequence X and sequence Y is defined by

d(X, Y) = max{d(X[i], Y[j]) | 0 <= i < n, 0 <= j < n}
You may assume 0 < n < 1000.

For example, for the sequences X and Y below, their maximum distance is reached for i=2 and j=7, so d(X, Y)=d(X[2], Y[7])=5.

                     i=2
                      |
                      v
          X     8  8  4  4  4  3  3  3  1 
                                              
          Y     9  9  8  8  6  5  5  4  3
                                     ^
                                     |
                                    j=7
*/
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> x;
vector<int> y;

int max(int a, int b){
    return (a > b) ? a : b;
}

int solve(){
    
    cin >> n;

    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        x.push_back(a);
    }
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        y.push_back(a);
    }

    int i = 0, j = 0, m = 0;

    while(i < n && j < n){
        if(x[i] <= y[j]){
            m = max(m, j - i);
            j++;
        }else{
            i++;
        }
    }

    cout << "The maximum distance is " << m << "\n";
    
    x.clear();
    y.clear();
}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}