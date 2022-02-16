/*
A spiral of numbers can start and end with any positive integers less than 100. Write a
program which will accept two positive integers x and y as input, and output a list of
numbers from x to y inclusive, shown in a spiral. You may assume that the end value is
greater than or equal to the start value.
A spiral starts with the first number in the centre. The next number appears immediately
below the first number. The spiral continues with the numbers increasing in a counterclockwise
direction until the last number is printed.
*/
#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    int a, b;
    cin >> a >> b;
    int i = 2; 
    int j = 0;
    int k = 0;

    while((b - a) - j >= 0){
        j = i * i;
        i += 2;
        k++;
    }
    int size = k * 2;
    int grid[100][100];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            grid[i][j] = 0;
        }
    }
    i = a;
    int x = k - 1, y = k - 1;
    int d = 3;
    int dir[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    while(i <= b){
        grid[x][y] = i;
        d++;
        if(d >= 4) d = 0;
        int x1 = x + dir[d][0];
        int y1 = y + dir[d][1];
        if(grid[x1][y1] != 0){
            d--;
            if(d < 0) d = 3;
        }
        x += dir[d][0];
        y += dir[d][1];
        i++;
    }
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            if(grid[c][r] == 0){
                cout << "   ";
            }else{
                cout << grid[c][r] << " ";
            }
        }
        cout << "\n";
    }
}

int main(void){

    solve();

    return 0;
}