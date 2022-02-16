/*
Write a program that repeatedly reads two numbers n and k and prints all bit patterns 
of length n with k ones in descending order (when the bit patterns are considered as 
binary numbers). You may assume that 30 >= n > 0, 8 > k >= 0, and n >= k. The first 
number in the input gives the number of pairs n and k. The numbers n and k are separated 
by a single space. Leading zeroes in a bit pattern should be included. See the example below.
*/
#include <iostream>
#include <vector>

using namespace std;

int number[30];
int n, k;

int permute(int i, int j){
    if(i == 0 && j == 0){
        for(int z = 0; z < n; z++) cout << number[z];
        cout << "\n";
    }
    if(i > j){number[n - i] = 0; permute(i - 1, j);}
    if(j > 0){number[n - i] = 1; permute(i - 1, j - 1);}
}

int solve(){
    cout << "the bit patterns are \n";
    cin >> n >> k;
    permute(n, k);
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}