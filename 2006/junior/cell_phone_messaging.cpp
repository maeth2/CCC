/*

*/
#include <string>
#include <iostream>

using namespace std;
using ll = long long;

int keys[26][2] = {{2, 0}, {2, 1}, {2, 2}, {3, 0}, {3, 1}, {3, 2}, {4, 0}, 
                    {4, 1}, {4, 2}, {5, 0}, {5, 1}, {5, 2}, {6, 0}, {6, 1}, 
                    {6, 2}, {7, 0}, {7, 1}, {7, 2}, {7, 3}, {8, 0}, {8, 1}, 
                    {8, 2}, {9, 0}, {9, 1}, {9, 2},{9, 3}};

void solve(){
    string s;
    cin >> s;
    while(s != "halt"){
        int time = 0;
        int prev = -1;
        for(char w : s){
            int c = w - 'a';
            if(keys[c][0] == prev){
                time += 2;
            }
            time += keys[c][1] + 1;
            prev = keys[c][0];
        }
        cout << time << '\n';
        cin >> s;
    }
}

int main(void){
    solve();
    return 0;
} 