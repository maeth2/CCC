/*
OK, you knew there had to be a Y2K problem, so here it is.
You are given a document containing text and numerical data, which may include dates. Your task is to
identify (two-digit) years and to reprint the document with these two-digit years replaced by four-digit
years. You may assume that any year numbered 24 or less is in the 2000's, while any year numbered 25
or more is in the 1900's (e.g. 16 represents the year 2016 and 26 represents the year 1926). Yes, we know
this rule may imply that your grandmother hasn't been born yet.
Your program is to recognize dates in any of three formats:
    dd/mm/yy
    yy.mm.dd
    Month,dd,yy
where dd is a two-digit day between 01 and 31, mm is a two-digit month between 01 and 12, yy is a twodigit year between 00 and 99, and Month is one of: January, February, March, April, May, June, July,
August, September, October, November, December. The first two formats contain no spaces, and the
third format contains a single space after Month and a single space after the comma.
Dates should appear on a single line. Dates traversing two lines or dates immediately adjacent to a letter
of the alphabet or a digit should not be recognized. Non-existent data such as February 30, 99 do not
need to be checked for.
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using ll = long long;

void solve(){
    string sentence;
    getline(cin, sentence);

    istringstream it(sentence);

    string word;

    int index = 0;

    string months[12] = {"January", "February", "March", "April", "May", "June", "July",
                        "August", "September", "October", "November", "December"};

    while(it >> word){
        bool hasPunctuation = false;
        char punctuation = ' ';
        if(word[word.size() - 1] == ',' || word[word.size() - 1] == '.'){
            hasPunctuation = true;
            punctuation = word[word.size() - 1];
            word.erase(word.size() - 1);
        }
        if(word.find('/') != word.npos && isdigit(word[0]) && word.size() == 8){
            try{
                int day = stoi(word.substr(0, 2));
                int month = stoi(word.substr(3, 2));
                int year = stoi(word.substr(6, 2));

                if(!(year > 99 || year < 0 || month > 12 || month < 1 || day > 31 || day < 1)){
                    if(year >= 25){
                        year += 1900;
                    }else{
                        year += 2000;
                    }
                    word = word.substr(0, 2) + "/" + word.substr(3, 2) + "/" + to_string(year);
                }
            }catch(exception &e){}
        }else if(word.find('.') != word.npos && isdigit(word[0]) && word.size() == 8){
            try{
                int day = stoi(word.substr(6, 2));
                int month = stoi(word.substr(3, 2));
                int year = stoi(word.substr(0, 2));
                if(!(year > 99 || year < 0 || month > 12 || month < 1 || day > 31 || day < 1)){
                    if(year >= 25){
                        year += 1900;
                    }else{
                        year += 2000;
                    }
                    word = to_string(year) + "/" + word.substr(3, 2) + "/" + word.substr(6, 2);
                }
            }catch(exception &e){}
        }else if(index != 0){
            index--;
            try{
                int a = stoi(word.substr(0, 2));
                if(index == 1){
                    if(a <= 99 && a >= 0){
                        if(a >= 25){
                            a += 1900;
                        }else{
                            a += 2000;
                        }
                    }
                    word = to_string(a);
                }else if(index == 2){
                    if(a < 0 || a > 31){
                        index = 0;
                    }
                }
            }catch(exception &e){
                index = 0;
            }
        }else{
            for(int i = 0; i < 12; i++){
                if(word == months[i]){
                    index = 3;
                }
            }
        }
        if(hasPunctuation) word += punctuation;
        cout << word << " ";
    }
    cout << "\n";
}

int main(void){
    int t;
    cin >> t;
    string none;
    getline(cin, none);
    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}