/*

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

string word[6] = {"WELCOME", "TO", "CCC" ,"GOOD" ,"LUCK", "TODAY"};

string justify(vector<string> s, int w){
    string a;
    int gaps = s.size() - 1;
    int total = 0;
    for(string b : s) total += b.size();
    int spaces = 0;
    if(gaps != 0) spaces = (w - total) / gaps;
    int extra = w - (total + gaps * spaces);
    for(string b : s){
        a += b;
        if(a.size() >= w) break;
        for(int j = 0; j < spaces; j++) a += '.';
        if(extra > 0){
            a += '.';
            extra--;
        }
    }
    for(int i = 0; i < extra; i++){
        a += '.';
    }
    cout << a << '\n';
    return a;
}

void solve(){
    float w;
    cin >> w;
    int length = 0;
    int index = -1;
    vector<string> r;
    for(int i = 0; i < 6; i++){
        index++;
        length += word[i].length();
        if(length + index > w){
            justify(r, w);
            r.clear();
            index = 0;
            length = word[i].length();
        }
        r.push_back(word[i]);
    }
    justify(r, w);
}

int main(void){
    solve();
    return 0;
}