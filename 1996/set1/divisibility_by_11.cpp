/*
Write a program which accepts as input a positive integer and checks, using the algorithm described below, 
to see whether or not the integer is divisible by 11. This particular test for divisibility by 11 was given 
in 1897 by Charles L. Dodgson (Lewis Carroll).

Algorithm:
As long as the number being tested has more than two digits, form a new number by:
deleting the units digit
subtracting the deleted digit from the shortened number
The remaining number is divisible by 11 if and only if the original number is divisible by 11.
Note:
Leading zeroes are not considered part of the number and should not be printed.
As usual, the first number in the input indicates the number of positive integers that follow. Each positive 
integer has a maximum of 50 digits. You may assume no leading zeroes exist in the positive integers.

For each positive integer in the input, the output consists of a series of numbers formed as a digit is deleted
and subtracted, followed by a message indicating whether or not the original number is divisible by 11. Outputs 
for different positive integers are separated by blank lines.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int solve(){
    string n;
    string n1;
    vector<int> number;
    cin >> n;
    n1 = n;
    cout << n << "\n";
    for(int i = 0; i<n.length(); i++) number.push_back(n[i]);
    
    while(n.length() > 2){
        for(int i = 0; i<n.length(); i++) number[i] = n[i] - '0';
        ll a = number.back();
        number.pop_back();
        n.pop_back();

        ll b = number.back();
        
        for(int i = 1; i<number.size(); i++){
            ll num = number[number.size() - 1 - i];
            b += num * pow(10, i);
            if (num != 0) break;
        }

        for(int i = 0; i<to_string(b).length(); i++) number.pop_back();

        string c = to_string(b-a);
        
        for(int i = 0; i < c.length(); i++){
            number.push_back(c[i] - '0');
        }
        
        if(number[0] == 0){
            number.erase(number.begin());
        }
        
        n.clear();

        for(int i = 0; i<number.size(); i++) n.push_back(number[i] + '0');
        cout << n << "\n";
    }
    
    cout << "The number " << n1 << ((11 % stoll(n) == 0) ? " is " : " is not ") << "divisible by 11.";

    return 0;
}

int main(){
    solve();
    return 0;
}