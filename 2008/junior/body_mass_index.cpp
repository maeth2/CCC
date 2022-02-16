/*

*/
#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    float weight, height;
    cin >> weight >> height;
    float bmi = weight / (height * height);
    if(bmi > 25){
        cout << "Overweight\n";
    }else if(bmi <= 25 && bmi >= 18.5){
        cout << "Normal weight\n";
    }else if(bmi < 18.5){
        cout << "Underweight\n";
    }
}

int main(void){
    solve();
    return 0;
}