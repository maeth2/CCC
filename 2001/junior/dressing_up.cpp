/*
It is important to keep our computers safe and clean. Some people feel that computers
should be well-dressed, also. For this question, you will write a program to print out a
bow tie on the computer screen.
*/
#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i+=2){
        for(int j = 0; j < n * 2; j++){
            if(j <= i || j >= n * 2 - 1 - i) cout << "*";
            else cout << " "; 
        }
        cout << "\n";
    }
    for(int i = n - 3; i >= 0; i-=2){
        for(int j = 0; j < n * 2; j++){
            if(j <= i || j >= n * 2 - 1 - i) cout << "*";
            else cout << " "; 
        }
        cout << "\n";
    }
}

int main(void){
    solve();
    return 0;
}