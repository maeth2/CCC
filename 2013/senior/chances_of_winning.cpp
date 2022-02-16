/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int t;

int recurse(vector<int> scores, vector<vector<bool>> matched, int g){
    if(g == 6){
        int max = -1;
        int n = 0;
        for(int i = 1; i <= 4; i++){
            if(scores[i] > max){
                max = scores[i];
                n = i;
            }else if(scores[i] == max){
                if(n == t){
                    n = i;
                }
            }
        }
        if(n == t) return 1;
        else return 0;
    }

    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 4; j++){
            if(i != j && !matched[i][j]){
                matched[i][j] = true;
                matched[j][i] = true;
                int total = 0;

                scores[i] += 3;
                total += recurse(scores, matched, g + 1);
                scores[i] -= 3;

                scores[j] += 3;
                total += recurse(scores, matched, g + 1);
                scores[j] -= 3;

                scores[i]++;
                scores[j]++;
                total += recurse(scores, matched, g + 1);

                return total;
            }
        }
    }
    return 0;
}
void solve(){
    int g;
    vector<int> scores(5);
    vector<vector<bool>> matched(5, vector<bool>(5));
    cin >> t >> g;
    for(int i = 0; i < g; i++){
         int a, b, a1, b1;
         cin >> a >> b >> a1 >> b1;
         if(a1 == b1){
            scores[a]++;
            scores[b]++;
         }else if(a1 > b1){
            scores[a] += 3;
         }else if(b1 > a1){
            scores[b] += 3;
         }
         matched[a][b] = true;
         matched[b][a] = true;
    }
    cout << recurse(scores, matched, g) << "\n";
}

int main(void){
    solve();
    return 0;
}