/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

string dict[8] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void solve(){
    int n;
    string number;
    cin >> n;
    while(n > 0){
        cin >> number;
        string nn = "";
        int count = 0;
        for(int j = 0; j < number.size(); j++){
            char c = number[j];
            if(c == '-') continue;
            count++;
            if(count > 10) break;
            for(int i = 0; i < 8; i++){
                if(dict[i].find(c) != dict[i].npos){
                    c = (i + 2) + '0';
                    break;
                }
            }
            nn += c;
            if(count == 3 || count == 6){
                nn += '-';
            }
        }
        cout << nn << "\n";
        n--;
    }
}

int main(void){
    solve();
    return 0;
}