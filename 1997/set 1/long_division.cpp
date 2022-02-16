/*
In days of yore (circa 1965), mechanical calculators performed division by shifting and repeated
subtraction. For example, to divide 987654321 by 3456789, the numbers would first be aligned
by their leftmost digit (see (1) below), and the divisor subtracted from the dividend as many
times as possible without yielding a negative number. The number of successful subtractions (in
this example, 2) is the first digit of the quotient. The divisor, shifted to the right (see (2) below),
is subtracted from the remainder several times to yield the next digit, and so on until the
remainder is smaller than the divisor.
*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;


int solve(){
    string a, b;
    cin >> a >> b;

    ll divisor = stoi(b);
    string dividend = a;
    ll remainder = stoi(a);   
    int shift = b.size();
    string ans = "";

    while (remainder >= divisor){
        int q = 0;
        ll d = stoi(dividend.substr(0, shift));
        string d1 = shift == dividend.size() ? " " : dividend.substr(shift, dividend.size() - shift);
        while(d - divisor >= 0){
            d -= divisor;
            q++;
        }
        string dd = to_string(d);
        dividend = dd + d1;
        remainder = stol(dividend);
        if(shift + 1 < dividend.size()) shift++;
        ans += q + '0';
    }
    cout << (ans == "" ? "0" : ans) << " " << remainder << "\n" ;
}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}