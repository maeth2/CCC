/*
If the Roman Empire had not fallen, then Rome would surely have discovered 
electricity and used electronic calculators; however, the Romans used Roman 
Numerals! Your task is to implement a simple Roman Calculator which accepts 
two Roman Numerals and outputs the sum in Roman Numerals. You may assume that 
numbers greater than 1000 will not occur in the input. Output numbers greater 
than 1000 are illegal and should generate the message CONCORDIA CUM VERITATE 
(In Harmony with Truth).

The input consists of a number, indicating the number of test cases, followed 
by this many test cases. Each test case consists of a single line with two numbers 
in Roman Numerals separated by a + along with an = at the end. There are no separating spaces.

For each test case the output is a copy of the input with the Roman Numeral that 
represents the sum. Outputs for different test cases are separated by a blank line.
*/
#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

map<char, int> dict = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
map<char, int> dict1 = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};


int itor(string a){
    int total = 0;
    for(int i = 0; i<a.length(); i++){
        if(a[i] == 'I'){
            if(a[i+1] == 'X' || a[i+1] == 'V'){
                total -= dict.at(a[i]);
                continue;
            }
        }else if(a[i] == 'X'){
            if(a[i+1] == 'L' || a[i+1] == 'C'){
                total -= dict.at(a[i]);
                continue;
            }
        }else if(a[i] == 'C'){
            if(a[i+1] == 'D' || a[i+1] == 'M'){
                total -= dict.at(a[i]);
                continue;
            }
        }
        total += dict.at(a[i]);
    }
    return total;
}

string rtoi(int number){
    int a = number;
    string ans = "";
    for(int i = 0; i<3; i++){
        int unit = pow(10, 2-i) + 0.5;
        int v = a - a % unit;
        a -= v;
        if(v != 0){
            v = v/unit;
            if(v == 9){
                ans.push_back(dict1.at(10 * unit / 10));
                ans.push_back(dict1.at(10 * unit));
            }else if(v == 4){
                ans.push_back(dict1.at(unit));
                ans.push_back(dict1.at(5 * unit));
            }else if(v < 4){
                for(int i = 0; i<v; i++){
                    ans.push_back(dict1.at(unit));
                }
            }else{
                ans.push_back(dict1.at(5 * unit));
                for(int i = 0; i<v-5; i++){
                    ans.push_back(dict1.at(unit));
                }
            }
        }
    }
    return ans;
}

int solve(){
    string plus = "+";
    string equals = "=";
    string equation;

    cin >> equation;

    string a = equation.substr(0, equation.find(plus));
    equation.erase(0, equation.find(plus) + 1);
    string b = equation.substr(0, equation.find(equals));

    int value = itor(a) + itor(b);
    
    cout << ((value > 1000) ? "CONCORDIA CUM VERITATE": rtoi(value)) << "\n";
}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}