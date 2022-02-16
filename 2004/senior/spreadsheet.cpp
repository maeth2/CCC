/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

string grid[10][9];
int values[10][9];

int travel(string a){
    int x, y, d, val;
    d = a.find('+');
    if(d == a.npos){
        y = a[0] - 'A';
        x = a[1] - '0' - 1;
        if(values[y][x] == -1) return -1;
        else return values[y][x];
    }else{
        string b = a.substr(0, d);
        a = a.substr(d + 1, a.size());
        y = b[0] - 'A';
        x = b[1] - '0' - 1;
        val = travel(a);
        if(val != -1){
            if(values[y][x] != -1){
                val += values[y][x];
                return val;
            }
        }
    }
    return -1;
}

void solve(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 9; j++){
            cin >> grid[i][j];
            values[i][j] = -1;
        }
    }

    bool changes = true;

    while(changes){
        changes = false;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 9; j++){
                if(values[i][j] != -1) continue;
                try{
                    values[i][j] = stoi(grid[i][j]);
                    changes = true;
                }catch(exception err){
                    int v = travel(grid[i][j]);
                    if(v != -1){
                        values[i][j] = v;
                        changes = true;
                    }
                }
            }
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 9; j++){
            if(values[i][j] == -1) cout << '*' << ' ';
            else cout << values[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void){
    solve();
    return 0;
}