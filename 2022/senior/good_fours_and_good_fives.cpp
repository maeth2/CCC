/*
Finn loves Fours and Fives. In fact, he loves them so much that he wants to know the number
of ways a number can be formed by using a sum of fours and fives, where the order of the
fours and fives does not matter. If Finn wants to form the number 14, there is one way to
do this which is 14 = 4 + 5 + 5. As another example, if Finn wants to form the number 20,
this can be done two ways, which are 20 = 4 + 4 + 4 + 4 + 4 and 20 = 5 + 5 + 5 + 5. As a final
example, Finn can form the number 40 in three ways: 40 = 4+4+4+4+4+4+4+4+4+4,
40 = 4 + 4 + 4 + 4 + 4 + 5 + 5 + 5 + 5, and 40 = 5 + 5 + 5 + 5 + 5 + 5 + 5 + 5.
Your task is to help Finn determine the number of ways that a number can be written as a
sum of fours and fives.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int n;
    int total = 0;
    cin >> n;
    int i = 1;
    for(int i = 0; i <= n / 4; i++){
        if((n - i * 4) % 5 == 0){
            total++;
        }
    }
    cout << total << '\n';
}

int main(void){
    solve();
    return 0;
}