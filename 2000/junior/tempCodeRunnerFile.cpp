/*
Write a program to print out a calendar for a particular month given the day on which the
first of the month occurs together with the number of days in the month.
*/
#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    int s,l;
    cin >> s;
    cin >> l;
    cout << "Sun Mon Tue Wed Thr Fri Sat\n";
    int day = 1;
    for(int r = 0; r < 5; r++){
        for(int c = 0; c < 7; c++){
            if(day > l) break;
            if(r == 0 && c < s - 1){
                cout << "   ";
            }else{
                cout << (day >= 10 ? " " : "  ") << day;
                day++;
            }
            if(c < 6 && day <= l) cout << " ";
        }
        if(day > l) break;
        cout << "\n";
    }
    cout << "\n";
}

int main(void){
    solve();
    return 0;
}