/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
int roman[26];

void solve(){
    string number;
    roman['I' - 'A'] = 1;
    roman['V' - 'A'] = 5;
    roman['X' - 'A'] = 10;
    roman['L' - 'A'] = 50;
    roman['C' - 'A'] = 100;
    roman['D' - 'A'] = 500;
    roman['M' - 'A'] = 1000;
    cin >> number;
    int num[number.size()/2];
    int bases[number.size()/2];
    int total = 0;
    for(int i = 0; i < number.size() / 2; i++){
        int n = number[i * 2] - '0';
        int m = roman[number[i * 2 + 1] - 'A'];
        num[i] = m * n;
        bases[i] = m;
        total += m * n;
    }
    
    for(int i = 0; i < number.size() / 2 - 1; i++){
        if(bases[i] < bases[i + 1]) total -= num[i] * 2;
    }
    cout << total << "\n";
}

int main(void){
    solve();
    return 0;
}