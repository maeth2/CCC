/*
Messages can be ciphered (encrypted) by systematically replacing letters of the alphabet by
other letters. A simple cipher known as the Caesar cipher replaces each letter in the alphabet 
by the letter k positions later in the alphabet, where A is considered to follow Z . For example, 
if k = 6, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, and Z would 
be replaced by G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, A, B, C, D, E, and F 
respecively. The message

   THE FULL MOON RISING IS A BAD SIGN

would be ciphered as

   ZNK LARR SUUT XOYOTM OY G HGJ YOMT

The inverse of the cipher is again a Caesar cipher with 26-k replacing k.

Your job as cryptanalist is to decode lines of text that have been encoded with 
a Ceasar cipher, each using a different unknown value of k. For example, if the input were

   ZNK LARR SUUT XOYOTM OY G HGJ YOMT
   FA NQ AD ZAF FA NQ FTMF UE FTQ CGQEFUAZ

the output would be

   THE FULL MOON RISING IS A BAD SIGN
   TO BE OR NOT TO BE THAT IS THE QUESTION

(the first line was ciphered with k=6 and the second line with k=12).
Of course there are 26 possible values of k and therefore 26 possible ciphers, so you will 
have to "guess" by selecting the most probable deciphering. The probability of a particular 
deciphering can be estimated using the probabilities of the letters it contains. In English,
E is the most common letter, with probability 0.127, T is the next more common with probability 
0.091, and so on. A complete table of letter probabilities is given below. The probability of a 
complete line of text can be approximated by the product of the probabilities of the letters it 
contains.
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;

float probabilities[26] = {0.082, 0.015, 0.028, 0.043, 0.127, 0.022,
                            0.020, 0.061, 0.070, 0.002, 0.008, 0.040,
                            0.024, 0.067, 0.075, 0.019, 0.001, 0.060, 
                            0.063, 0.091, 0.028, 0.010, 0.023, 0.001, 
                            0.020, 0.001};
                                                        
int solve(){
    string sentence;
    getline(cin, sentence);

    float probability = INT32_MAX;
    int k = -1;
    for(int i = 0; i < 26; i++){
        float current_probability = 1;
        float expected_probability = 1;
        float count[26];
        for(int i = 0; i < 26; i++) count[i] = 0;
        float total = 0;

        for(int j = 0; j < sentence.size(); j++){
            if(sentence[j] == ' ') continue;
            int a = sentence[j] - 'A' + i;
            char l = a % 26 + 'A';
            count[a % 26]++;
            total++;
        }

        for(int j = 0; j < 26; j++){
            if(count[j] == 0) continue;
            current_probability += fabs(count[j] / total - probabilities[j]);
            expected_probability *= probabilities[j];
        }

        if(current_probability < probability){
            probability = current_probability;
            k = i;
        }
    }

    for(int i = 0; i < sentence.size(); i++){
        if(sentence[i] == ' '){
            cout << ' ';
            continue;
        }
        char a = (((sentence[i] - 'A') + k) % 26) + 'A';
        cout << a;
    }
    cout << "\n";
}

int main(void){
    int t;
    string none;
    cin >> t;

    getline(cin, none);

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}