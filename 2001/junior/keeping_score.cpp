/*
In a card game, each player's hand is made up of 13 cards. Each hand has a total point
value determined by the number of cards that have a point value. The cards which are
worth points are the Ace (4 points), King (3 points), Queen (2 points) and Jack (1 point).
The other cards (2, 3, 4, 5, 6, 7, 8, 9, 10) have no point value. There are four of each type
of card, one in each of the four suits. The suits are called clubs (C), diamonds (D), hearts
(H), and spades (S). As well, points are assigned for each suit which has a void (3 points),
a singleton (2 points), or a doubleton (1 point). A void in a suit means that there are no
cards of that suit (e.g. a hand with no spades). A singleton in a suit means that there is
only one card in that suit (e.g. a hand with only one diamond). A doubleton in a suit
means that there are only two cards in that suit.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

string names[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};

void solve(){
    string hand;
    cin >> hand;
    
    int s[26];
    for(int i = 0; i < 26; i++) s[i] = -1;
    s['C' - 'A'] = 0;
    s['D' - 'A'] = 1;
    s['H' - 'A'] = 2;
    s['S' - 'A'] = 3;
    vector<vector<char>> suits(4);
    int index = -1;
    for(int i = 0; i < hand.size(); i++){
        int n = hand[i] - 'A';
        if(n >= 0 && n < 26 && s[n] != -1){
            index = s[n];
            continue;
        }
        suits[index].push_back(hand[i]);
    }
    cout << "Cards Dealt            Points\n";
    int total = 0;
    for(int i = 0; i < 4; i++){
        cout << names[i] << " ";
        int points = 3 - suits[i].size();
        if(points < 0) points = 0;
        for(int j = 0; j < suits[i].size(); j++){
            if(suits[i][j] == 'A') points += 4;
            if(suits[i][j] == 'K') points += 3;
            if(suits[i][j] == 'Q') points += 2;
            if(suits[i][j] == 'J') points += 1;
            cout << suits[i][j] << " ";
        }
        total += points;
        cout << "      " << points << "\n";
    }
    cout << "Total " << total;
}

int main(void){
    solve();
    return 0;
}