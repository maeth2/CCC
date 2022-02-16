/*

*/
#include <iostream>
#include <string>
#include <vector>

#define vs vector<string>

using namespace std;
using ll = long long;

/*
+ - 3 2 4
post = ? rest = + - 3 2 4
    post1 = ?  rest1 = - 3 2 4
        post2 = 3 rest2 = 2 4
            post2 = 2 rest2 = 4
    post = 3 2 - rest = 4
        post = 3 2 - 4 + rest = 
        
    

*/
vs recurse(string rest){
    vs c(2);
    if(rest[0] == '+' || rest[0] == '-'){
        vs a, b;
        char o = rest[0];
        a = recurse(rest.erase(0, 1));
        b = recurse(a[1]);
        c[0] = a[0] + ' ' + b[0] + ' ' + o;
        c[1] = b[1];
    }else{
        c[0] = rest[0];
        if(rest.length() > 1){
            c[1] = rest.erase(0, 1);
        }else{
            c[1] = "";
        }
    }
    return c;
}
void solve(){
    while(true){
        string i, prfxexp, pstexp;
        getline(cin, i);
        for(char c : i){
            if(c != ' ') prfxexp += c;
        }
        if(prfxexp == "0") break;
        pstexp = recurse(prfxexp)[0];
        cout << pstexp << '\n';
    }
}

int main(void){
    solve();
    return 0;
}