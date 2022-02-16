/*

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

vector<int> before;
vector<int> after;
vector<int> searched(7);

bool check(int i){
    bool ok = !searched[i];
    if(ok){
        bool na = true;
        for(int j : after){
            if(j == i){
                na = false;
            }
        }
        if(!na){
            bool tbd = true;
            for(int j = 0; j < after.size(); j++){
                if(after[j] == i && !searched[before[j]]){
                    tbd = false;
                }
            }
            ok = tbd;
        }
    }
    return ok;
}

void solve(){
    before.push_back(0);
    after.push_back(6);
    before.push_back(0);
    after.push_back(3);
    before.push_back(1);
    after.push_back(0);
    before.push_back(2);
    after.push_back(3);
    before.push_back(2);
    after.push_back(4);

    int a, b = -1;
    cin >> a >> b;
    while(a != 0 && b != 0){
        before.push_back(a - 1);
        after.push_back(b - 1);
        cin >> a >> b;
    }

    bool doit = false;
    int k = 1;
    string answer;
    for(int k = 0; k < 7; k++){
        bool stop = false;
        for(int i = 0; i < 7; i++){
            if(!searched[i] && check(i)){
                searched[i] = 1;
                answer += i + 1 + '0';
                answer += ' ';
                stop = true;
                break;
            }
        }
        if(!stop){
            cout << "\nCannot complete these tasks.  Going to bed.\n";
            doit = true;
            break;
        }
    }
    if(!doit){
        cout << answer << "\n";
    }

}

int main(void){
    solve();
    return 0;
}