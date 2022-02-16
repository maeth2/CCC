/*
In chess, game pieces move about an 8 ¥8 chessboard in a fashion defined by their type. The object of
the game is to capture opposing pieces by landing on their squares, and eventually trapping the king
piece.

In our version of the game, we shall use a variable sized board with only 2 pieces on it: A white pawn
which moves relentlessly towards the top row of the chessboard one square at a time per move; and a
black knight which can move from its current location in any of up to eight ways: two squares up or
down and one square left or right, or one square up or down and two squares left or right. The knight
must remain on the board at all times; any move that would take it off the board is therefore disallowed.
In the diagram below, the knight's position is labelled K and its possible moves are labelled 1 to 8.
 . . . . . . .
 . . 8 . 1 . .
 . 7 . . . 2 .
 . . . K . . .
 . 6 . . . 3 .
 . . 5 . 4 . .
 . . . . . . .
The pawn moves first; then the knight and pawn alternate moves. The knight tries to land either on the
square occupied by the pawn (a win) or on the square immediately above the pawn (a stalemate). If the
pawn reaches the top row of the board the game ends immediately and the knight loses (a loss).
Write a program to determine whether the knight can win and, if it can, the minimum number of moves
it must make to do so. If the knight cannot win, your program should determine if it can cause a
stalemate and, if it can, the minimum number of moves it must make to do so. Finally if the knight
cannot win or cause a stalemate, your program should compute the number of moves the knight makes
before the pawn wins.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using ll = long long;

int max(int a, int b){
    return a > b ? a : b;
}

int moves[8][2] = {{2, 1}, {2, -1},
                    {-2, 1}, {-2, -1},
                    {1, 2}, {-1, 2},
                    {1, -2}, {-1, -2}};


int solve(){
    int row, col, pr, pc, kr, kc;
    cin >> row >> col >> pr >> pc >> kr >> kc;
    pr = row - pr;
    pc -= 1;
    kr = row - kr;
    kc -= 1;
    vector<vector<int>> grid(row, vector<int>(col));
    vector<vector<int>> searched(row, vector<int>(col));
    queue<tuple<int, int, int>> pq;
    pq.emplace(kr, kc, 0);
    searched[kr][kc] = 1;

    int num = 0;
    while(!pq.empty()){
        int r = get<0>(pq.front());
        int c = get<1>(pq.front());
        int m = get<2>(pq.front());
        pq.pop();
        for(int i = 0; i < 8; i++){
            int nr = r + moves[i][0];
            int nc = c + moves[i][1];
            if(nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
            if(searched[nr][nc]) continue;
            searched[nr][nc] = 1;
            grid[nr][nc] = m + 1;
            pq.emplace(nr, nc, m + 1);
        }
        num++;
    }

    bool won = false;
    for(int r = pr; r >= 0; r--){
        if((grid[r][pc] - (pr - r) % 2) == 0){
            cout << "WON " << (pr - r) << "\n";
            won = true;
            break;
        }
    }

    if(!won){
        for(int r = pr - 1; r >= 0; r--){
            if((grid[r][pc] - (pr - r + 1) % 2) == 0){
                cout << "STALEMATE " << (pr - r) << "\n";
                won = true;
                break;
            }
        }
    }

    if(!won) cout << "LOST " << pr - 1  << "\n"; 
    
}

int main(void){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}