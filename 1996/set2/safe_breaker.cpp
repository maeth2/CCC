/*
We are observing someone playing a game similar to Mastermind (TM). The object of this 
game is to find a secret code by intelligent guesswork, assisted by some clues. In this 
case the secret code is a 4-digit number in the inclusive range from 0000 to 9999, say 
"3321". The player makes a first random guess, say "1223" and then, as for each of the future 
guesses, gets a clue telling how close the guess is. A clue consists of two numbers: the number 
of correct digits (in this case, one: the "2" at the third position) and the additional number 
of digits guessed correctly but in the wrong place (in this case, two: the "1" and the "2"). 
The clue would in this case be: "1/2". For the guess "1110", the clue would be "0/1", since there 
are no correct digits and only one misplaced digit. (Notice that there is only one digit 1 misplaced.)

Write a program that, given a set of guesses and corresponding clues, tries to find the secret code.
*/
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int solve(){
    int n;

    cin >> n;
    
    vector<tuple<string, int, int>> conditions;
    
    
    for(int i = 0; i < n; i++){
        string clue;
        string current_digit;
        cin >> current_digit >> clue;
        
        int right_pos = stoi(clue.substr(0,clue.find("/")));
        int right_digit = stoi(clue.substr(clue.find("/") + 1, clue.length() - 1));
        
        conditions.emplace_back(current_digit, right_pos, right_digit);
    }

    bool found = true;
    vector<int> corrects;

    for(int i = 0; i < 10000; i++){
        string a = to_string(i);
        found = true;
        for(int j = 0; j < 4 - a.length(); j++) a.insert(0, "0");
        for(int j = 0; j < conditions.size(); j++){
            string b = a;
            string digits = get<0>(conditions[j]);
            int p = get<1>(conditions[j]);
            int d = get<2>(conditions[j]);
            int cd = 0;
            int cp = 0;

            for(int z = 0; z < 4; z ++){
                if(digits[z] == b[z]){
                    digits[z] = 'x';
                    b[z] = 'y';
                    cp ++;
                }
            }
            for(int z = 0; z < 4; z ++){
                if(digits.find(b[z]) != std::string::npos){
                    digits[digits.find(b[z])] = 'x';
                    b[z] = 'y';
                    cd ++;
                }
            }
            
            if(cd == d && cp == p){
                continue;
            }else{
                found = false;
                break;
            }
        }
        if(found){
            corrects.push_back(i);
        }
    }

    if(corrects.size() == 0) cout << "impossible" << "\n";
    if(corrects.size() > 1) cout << "indeterminate" << "\n";
    if(corrects.size() == 1) cout << "password is " << corrects[0] << "\n";
}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}