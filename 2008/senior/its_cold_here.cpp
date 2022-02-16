/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int min = INT16_MAX;
    string c;
    while(true){
        string city;
        int temperature;
        cin >> city >> temperature;
        if(temperature < min){
            c = city;
            min = temperature;
        }
        if(city == "Waterloo"){
            break;
        }
    }
    cout << c << "\n";
}

int main(void){
    solve();
    return 0;
}