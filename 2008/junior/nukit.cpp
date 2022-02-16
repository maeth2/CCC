/*

*/
#include <iostream>

using namespace std;
using ll = long long;

int reactions[5][4] = {{2, 1, 0 ,2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};
bool wp[9][9][9][9];

bool check_losing(int a, int b, int c, int d){
    if(a < 0 || b < 0 || c < 0 || d < 0){
        return false;
    }else{
        return !wp[a][b][c][d]; 
    }
}
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                for(int z = 0; z < 9; z++){
                    wp[i][j][k][z] = false;
                }
            }
        }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                for(int z = 0; z < 9; z++){
                    for(int h = 0; h < 5; h++){
                        if(check_losing(i - reactions[h][0], j - reactions[h][1], k - reactions[h][2], z - reactions[h][3])){
                            wp[i][j][k][z] = true;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        // for(int h = 0; h < 5; h++){
        //     int a1 = a - reactions[h][0];
        //     int b1 = b - reactions[h][1];
        //     int c1 = c - reactions[h][2];
        //     int d1 = d - reactions[h][3];
        //     if(a1 < 0 || b1 < 0 || c1 < 0 || d1 < 0) continue;
        //     cout << a1 << ' ' << b1 << ' ' << c1 << ' ' << d1 << ' ' << wp[a1][b1][c1][d1] << "\n";
        // }
        if(wp[a][b][c][d]){
            cout << "Patrick\n";
        }else{
            cout << "Roland\n";
        }
    }
}

int main(void){
    solve();
    return 0;
}