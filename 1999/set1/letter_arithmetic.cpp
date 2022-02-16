/*
A popular form of pencil game is to use letters to represent digits in a mathematical statement. An
example is

 SEND
 +MORE
 -----
 MONEY

which represents

 9567
 +1085
 -----
 10652

Your task is to read in sets of three “words” and assign unique digits to the letters in such a way as to
make the sum of the first two words equal to the third word.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

string v = "0123456789";

int p = 0;

int toInt(string word, vector<char> &perm, int pos, int number){
    char letter;
    int j = word.size() - pos;
    if(j < 0) return 0;
    letter = word[j];
    for(int i = 0; i < 10; i++){
        if(perm[i] == letter){
            return i;
        }
    }

    if(perm[number] == ' '){
        perm[number] = letter;
        return number;
    }

    return -1;
}

int solution(vector<string> words, int position, int carry, vector<char> perm){
    vector<char> thisPerm = perm;
    int hashTable[1000];
    for(int i = 0; i < 1000; i++) hashTable[i] = 0;
    int sum, hash;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                int a = toInt(words[0], thisPerm, position, i);
                int b = toInt(words[1], thisPerm, position, j);
                int c = toInt(words[2], thisPerm, position, k);

                hash = a * 100 + b * 10 + c;
                
                if(a >= 0 && b >= 0 && c >= 0 && hashTable[hash] == 0){
                    sum = carry + a + b - c;
                    if(sum % 10 == 0){
                        if(position == words[2].length()){
                            if(sum == 0 && c > 0){
                                for(int z = 0; z < 3; z++){
                                    for(int d = words[z].size(); d > 0 ; d--){
                                        cout << toInt(words[z], thisPerm, d, 0);
                                    }
                                    cout <<"\n";
                                }
                                return 1;
                            }
                        }else if(solution(words, position + 1, sum / 10, thisPerm)) return 1;
                    }
                    hashTable[hash] = 1;
                }

                thisPerm = perm;
            }
        }
    }
    return 0;
}    

int solve(){
    string a, b, c;
    cin >> a >> b >> c;

    vector<char> perm(10);

    vector<string> words;
    words.push_back(a);
    words.push_back(b);
    words.push_back(c);
    
    for(int i = 0; i < 10; i++) perm[i] = ' ';

    solution(words, 1, 0, perm);
}

int main(void){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}