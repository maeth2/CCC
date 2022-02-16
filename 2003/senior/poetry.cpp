/*

*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using ll = long long;

string vowels = "aeiou";

void solve(){
    int n;
    cin >> n;
    string verses[5][4];
    string c;
    getline(cin, c);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            getline(cin, c);
            istringstream iss(c);
            string word, syllable = "";
            while(iss >> word){}
            for(int k = word.size() - 1; k >= 0; k--){
                char z = tolower(word[k]);
                syllable += z;
                if(vowels.find(z) != vowels.npos) break;
            }
            verses[i][j] = syllable;
        }
    }

    for(int i = 0; i < n; i++){
        if(verses[i][0] == verses[i][1] && verses[i][0] == verses[i][2]  && verses[i][0] == verses[i][3]) cout << "perfect\n";
        else if(verses[i][0] == verses[i][1] && verses[i][2] == verses[i][3]) cout << "even\n";
        else if(verses[i][0] == verses[i][2] && verses[i][1] == verses[i][3]) cout << "cross\n";
        else if(verses[i][0] == verses[i][3] && verses[i][1] == verses[i][2]) cout << "shell\n";
        else cout << "free\n";
    }
}

int main(void){
    solve();
    return 0;
}