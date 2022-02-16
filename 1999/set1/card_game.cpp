/*
Write a program that will keep score for a simple two-player game, played with a deck of cards. There
are 52 cards in the deck; four of each of 13 possible names: two, three, four, five, six, seven, eight, nine,
ten, jack, queen, king, ace. The cards labelled jack, queen, king, ace are collectively known as high
cards.

The deck is shuffled and placed face-down on the table. Player A turns over the top card and places it on
a pile; then player B turns over the top card and places it on the pile. A and B alternate until the deck is
exhausted. The game is scored as follows:
    • if a player turns over an ace, with at least 4 cards remain to be turned over, and none of the
    next 4 cards is a high card, that player scores 4 points
    • if a player turns over a king, with at least 3 cards remain to be turned over, and none of the next
    3 cards is a high card, that player scores 3 points
    • if a player turns over a queen, with at least 2 cards remain to be turned over, and none of the
    next 2 cards is a high card, that player scores 2 points
    • if a player turns over a jack, with at least 1 card remains to be turned over, and the next card is
    not a high card, that player scores 1 point
*/
#include <iostream>
#include <string>
using namespace std;
using ll = long long;

string high[4] = {"jack", "queen", "king", "ace"};
int points[4] = {1, 2, 3, 4};

int solve(){
    string cards[52];
    int players[2] = {0, 0};
    int count = 0;
    int point = 0;
    for(int i = 0; i < 52; i++){
        cin >> cards[i];
    }

    for(int i = 0; i < 52; i++){
        count--;

        for(int j = 0; j < 4; j++){
            if(cards[i] == high[j]){
                count = points[j];
                point = points[j];
                break;
            }
        }

        if(count == 0){
            int p = (i - point) % 2;
            players[p] += point;
            cout << "Player " << (p == 0 ? 'A' : 'B') << " scores " << point << " point(s)\n";
            point = 0;
        }
    }

    cout << "Player A: " << players[0] << " points(s)\n";
    cout << "Player B: " << players[1] << " points(s)\n";
}

int main(void){
    solve();

    return 0;
}