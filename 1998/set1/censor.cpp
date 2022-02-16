/*
The Society for Prevention of Profanity on the Internet has observed a growing number of
chat lines on the World Wide Web. A chat line allows a Web user to type lines of text
which are transmitted to all other users. The Society is concerned about the number of fourletter 
words being transmitted by these chat lines and has proposed the mandatory use of
software to remove all four-letter words from every transmission. Your job is to write the
software to do this removal.
The input to your program consists of an integer, n, on a line by itself, followed by n lines
of text. Each line of text contains words separated by spaces. Each word consists of letters
of the alphabet and exactly one space separates adjacent words. There are no spaces before
the first word or after the last word on each line. Lines do not exceed 80 characters in
length.

The output from your program should consist of the n lines of text, with each four-letter
word replaced by four asterisks. The lines should be separated by one blank line.

*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using ll = long long;

int solve(){
    int n;
    string a;
    cin >> n;
    getline(cin, a);
    string word;

    for(int i = 0; i < n; i++){
        getline(cin, a);
        istringstream iss(a);
        while(iss >> word){
            if(word.size() == 4){
                cout << "**** ";
            }else{
                cout << word << " ";
            }
        }
        cout << "\n";
    }
}

int main(void){
    solve();
    return 0;
}