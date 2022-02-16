/*
Write a program that repeatedly reads a positive integer, determines if the integer is
deficient, perfect, or abundant, and outputs the number along with its classification.

A positive integer, n, is said to be perfect if the sum of its proper divisors equals 
the number itself. (Proper divisors include 1 but not the number itself.) If this sum 
is less that n, the number is deficient, and if the sum is greater than n, the number 
is abundant.

The input starts with the number of integers that follow. For each of the following integers,
your program should output the classification, as given below. You may assume that the input
integers are greater than 1 and less than 32500.
*/
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string solve(){
    string ans;
    int n;
    int total = 0;
    cin >> n;

    for(int i = 1; i <= sqrt(n); i++){ //simple Trial division algorithm
        if(n % i == 0){
            int j = n/i;
            if(j >= n) j = 0; 
            total += i;
            total += (i == j) ? 0 : j;
        }
    }

    if(total < n) ans = "deficient";
    else if(total > n) ans = "abundant";
    else if(total == n) ans = "perfect";
    return ans;
}

int main(){
    cout << solve();
    return 0;
}