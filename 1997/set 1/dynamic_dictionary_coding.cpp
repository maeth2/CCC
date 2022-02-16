/*
A common method of data compression, "dictionary coding", is to replace words in a text by
numbers indicating their positions in a dictionary. Static dictionary coding, in which the
dictionary is known in advance, can be problematic, as it is necessary to have the dictionary
available to understand the coded text. Dynamic dictionary coding avoids this problem by
deriving the dictionary from the text to be compressed. The text is processed from beginning to
end, starting with an empty dictionary. Whenever a word is encountered that is in the dictionary,
it is replaced by a number indicating its position in the dictionary. Whenever a word is
encountered that is not in the dictionary, it appears as-is in the compressed text and is added to
the end of the dictionary.
(a) You are to implement dynamic dictionary coding
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int solve(){
    string s;
    vector<string> dict;
    getline(cin, s);
    while(!s.empty()){
        istringstream it(s);
        string word;
        string sentence = "";
        if(s.empty()) break;
        while(it >> word){
            auto index = find(dict.begin(), dict.end(), word);
            if(index != dict.end()){
                sentence += " " + to_string(index - dict.begin() + 1) + " ";
            }else{
                sentence += " " + word + " ";
                dict.push_back(word);
            }
        }
        cout << sentence << "\n";
        getline(cin, s);
    }
}
int main(){
    int t;
    string s;
    cin >> t;
    getline(cin, s);
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}