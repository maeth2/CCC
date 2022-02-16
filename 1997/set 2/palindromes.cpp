/*
A palindrome is a sequence of characters that reads the same forwards and backwards. e.g. RADAR, MADAMIMADAM
You are to write a program which finds the longest palindrome in a given string of characters.
*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int solve(){
    string a;
    cin >> a;

    string ans = "";

    for(int i = 0; i < a.size(); i++){
        for(int j = i + 1; j < a.size(); j++){
            if(a[i] == a[j]){
                string p = "";
                bool complete = true;
                int middle = ((j - i) + (j - i) % 2) / 2;
                for(int z = 0; z <= middle; z++){
                    if(a[i + z] != a[j - z]){
                        p.clear();
                        complete = false;
                        break;
                    }
                    p.push_back(a[i + z]);
                }
                if(complete) for(int k = p.size() - 1 - ((j - i + 1) % 2); k >= 0; k--) p.push_back(p[k]);
                if(ans.size() < p.size()) ans = p;
            }
        }
    }

    cout << ans;
}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}