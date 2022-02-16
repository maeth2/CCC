/*
Write a program which accepts as input a list of subjects, a list of verbs, and a list of objects, and
produces all possible sentences which consist of a subject, a verb, and an object.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(){
    int s, v, o;
    vector<vector<string>> words(3);
    cin >> s >> v >> o;
    string a;
    getline(cin, a);
    for(int i = 0; i < s; i++){ 
        getline(cin, a);
        cout << a << " : 0 \n";
        words[0].push_back(a);
    }

    for(int i = 0; i < v; i++){
        getline(cin, a);
        cout << a << " : 1 \n";
        words[1].push_back(a);
    }

    for(int i = 0; i < o; i++){
        getline(cin, a);
        cout << a << " : 2 \n";
        words[2].push_back(a);
    }

    for(int i = 0; i < words[0].size(); i++){
        for(int j = 0; j < words[1].size(); j++){
            for(int k = 0; k < words[2].size(); k++){
                cout << words[0][i] << " " << words[1][j] << " " << words[2][k] << "\n";
            }   
        }   
    }

}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}