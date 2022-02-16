/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int genes[5][2];

bool isLower(char a){
    if(a - 'A' < 26) return false;
    return true;
}

void solve(){
    string p1, p2;
    cin >> p1 >> p2;
    for(int i = 0; i < 5; i++){
        bool a[2][2] = {{isLower(p1[i * 2]), isLower(p1[i * 2 + 1])}, {isLower(p2[i * 2]), isLower(p2[i * 2 + 1])}};
        bool reccessive = false, dominant = false;
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                if(!a[0][j] || !a[1][k]){
                    dominant = true;
                }else if(a[0][j] && a[1][k]){
                    reccessive = true;
                }
            }
        }
        genes[i][0] = dominant;
        genes[i][1] = reccessive;    
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string pheno;
        cin >> pheno;
        bool possible = true;
        for(int j = 0; j < 5; j++){
            bool recessive = isLower(pheno[j]);
            if((recessive && !genes[j][1]) || (!recessive && !genes[j][0])){
                possible = false;
                break;
            }
        }
        if(!possible) cout << "Not their baby!\n";
        else cout << "Possible baby.\n";
    }
}

int main(void){
    solve();
    return 0;
}