/*
A fractal is a geometrical object with the property that subsections of the object appear identical to (but
smaller than) the whole object.

Write a program to compute the specified function after n iterations(n £ 5). To do this, represent the
figure as a 3n
 by 3n
 grid, with '*' to indicate filled areas and ' ' to indicate unfilled areas. The figure will
be too large to print on a single screen or sheet of paper so the input will specify a small rectangular
portion of the figure to be printed.
The first line of input contains a positive integer d, indicating the number of test data sets to follow.
Each data set consists of five lines containing:
    • n, the number of iterations
    • b, the bottom row of the rectangle to be printed 1 £ b £ 3n ( ) • t, the top row of the rectangle to be printed
    • l, the left column of the rectangle to be printed 
    • r, the right column of the rectangle to be printed
Note that rows are numbered from bottom to top and columns from left to right.
Compute the figure and print the specified rectangular portion, with one line of output per row. Print the
top row first, and the bottom row last. To make the output appear square, leave a single horizontal space
between row elements (as is done in the examples above). Leave a blank line in the output after every
test case.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

vector<vector<char>> recurse(int size, int layer){
    vector<vector<char>> grid(size, vector<char>(size));
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            if(r >= size / 3 && r < (size / 3) * 2 && c >= size / 3 && c < (size / 3) * 2){
                grid[r][c] = ' ';
            }else{
                grid[r][c] = '*';
            }
        }
    }
    if(layer == 0) return grid;
    for(int r1 = 0; r1 <= 2; r1++){
        for(int c1 = 0; c1 <= 2; c1++){
            if(r1 == 1 && c1 == 1) continue;
            int subsize = size / 3; 
            vector<vector<char>> subgrid = recurse(subsize, layer - 1);
            for(int r = 0; r < subsize; r++){
                for(int c = 0; c < subsize; c++){
                    grid[r + r1 * subsize][c + c1 * subsize] = subgrid[r][c];
                }
            }
        }
    }
    return grid;
}

int solve(){
    int n, bottom, top, left, right;
    cin >> n >> bottom >> top >> left >> right;
    int size = pow(3, n);
    vector<vector<char>> grid(size, vector<char>(size));
    grid = recurse(size, n);
    for(int r = size - top; r <= size - bottom; r++){
        for(int c = left - 1; c < right; c++){
            cout << grid[r][c] << " ";
        }
        cout << "\n";
    }
}

int main(void){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}