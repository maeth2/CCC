/*
Given an m by n grid of letters and a list of words, find the location in the 
grid at which the word can be found. A word matches a straight, uninterrupted 
line of letters in the grid, regardless of case. The matching can be done in any 
of the eight directions either horizontally, vertically or diagonally through 
the grid.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int m, n, k;

bool check_letters(int r, int c, string word, vector<vector<char>> grid){
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0) continue;
            for(int z = 1; z < word.length(); z++){
                int c1 = c + j * z;
                int r1 = r + i * z;
                if(r1 >= m || r1 < 0 || c1 >= n || c1 < 0) break;
                if(grid[r1][c1] != word[z]) break;
                if(z == word.length() - 1) return true;
            }
        }
    }
    return false;
}

int solve(){
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    vector<string> word_list; 
    
    for(int r = 0; r < m; r++){
        for(int c = 0; c < n; c++){
            char a;
            cin >> a;
            if(a >= 97 && a <= 122) {
                a = a - 32;
            }
            grid[r][c] = a;
        }
    }

    cin >> k;

    for(int i = 0; i < k; i++){
        string a;
        cin >> a;
        for(int j = 0; j < a.length(); j++){
            if(a[j] >= 97 && a[j] <= 122) {
                a[j] = a[j] - 32;
            }
        }
        word_list.push_back(a);
    }

    bool br = false;
    for(int i = 0; i < k; i++){
        br = false;
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == word_list[i].front()){
                    if(check_letters(r, c, word_list[i], grid)){
                        cout << r + 1 << " " << c + 1 << "\n";
                        br = true;
                    }
                }
                if(br) break;
            }
            if(br) break;
        }
    }

}

int main(){
    int t;
    cin >> t;
    
    for(int c = 0; c<t; c++){
        solve();
    }

    return 0;
}