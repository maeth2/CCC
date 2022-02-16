/*

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int m, n;
vector<string> names;
vector<int> times;

int max(int a, int b){return a > b ? a : b;}
void solve(){
    cin >> m >> n;
    vector<int> best;
    vector<int> group;

    for(int i = 0; i < n; i++){
        string name;
        int time;
        cin >> name >> time;
        names.push_back(name);
        times.push_back(time);
    }
    for(int i = 0; i < n + 1; i++){
        best.push_back(INT16_MAX);
        group.push_back(-1);
    }

    best[0] = 0;
    group[0] = 0;

    for(int i = 0; i < n + 1; i++){
        int curr = 0;
        for(int j = 1; j <= m && j + i - 1 < n; j++){
            curr = max(curr, times[i + j - 1]);
            if(best[i] + curr < best[i + j]){
                best[i + j] = best[i] + curr;
                group[i + j] = j;
            }
        }
    }

    cout << "Total Time: " << best[n] << "\n";

    vector<int> split;
    int k = n;

    while(group[k] != 0){
        split.push_back(group[k]);
        k -= group[k];
    }

    int x = 0;
    for(int i = split.size() - 1; i >= 0; i--){
        for(int j = 0; j < split[i]; j++){
            cout << names[x++] << " ";
        }
        cout << "\n";
    }

}

int main(void){
    solve();
    return 0;
}