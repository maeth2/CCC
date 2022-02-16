/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

/*
CU	see you
:-)	I'm happy
:-(	I'm unhappy
;-)	wink
:-P	stick out my tongue
(~.~)	sleepy
TA	totally awesome
CCC	Canadian Computing Competition
CUZ	because
TY	thank-you
YW	you're welcome
TTYL	talk to you later
*/

string sf[12] = {"CU", ":-)", ":-(", ";-)", ":-P", "(~.~)", "TA", "CCC", "CUZ", "TY", "YW", "TTYL"};
string lf[12] = {"see you", "I'm happy", "I'm unhappy", "wink", "stick out my tongue", "sleepy", "totally awesome", "Canadian Computing Competition",
                 "because", "thank-you", "you're welcome", "talk to you later"};
void solve(){
    while(true){
        string in;
        cin >> in;
        bool found = false;
        for(int i = 0; i < 12; i++){
            if(in == sf[i]){
                cout << lf[i] << '\n';
                found = true;
                break;
            }
        }
        if(!found) cout << in << '\n';
        if(in == "TTYL") break;
    }
}

int main(void){
    solve();
    return 0;
}