/*
Prim's Algorithm
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

int max(int a, int b){return a > b ? a : b;}
int min(int a, int b){return a < b ? a : b;}

void solve(){
    int c, r, d;
    cin >> c >> r >> d;
    vector<vector<int>> weights(c + 1, vector<int>(c + 1));
    vector<vector<int>> paths(c + 1);
    vector<int> dest;

    for(int i = 1; i < c + 1; i++){
        for(int j = 1; j < c + 1; j++){
            weights[i][j] = -1;
        }
    }

    for(int i = 0; i < r; i++){
        int a, b, w;
        cin >> a >> b >> w;
        if(weights[a][b] == -1){
            paths[a].push_back(b);
            paths[b].push_back(a);
        }
        if(w > weights[a][b]){
            weights[a][b] = w;
            weights[b][a] = w;
        }
    }

    for(int i = 0; i < d; i++){
        int d;
        cin >> d;
        dest.push_back(d);
    }

    priority_queue<pair<int, int>> pq;
    vector<int> searched(c + 1);

    pq.emplace(INT16_MAX, 1);

    vector<int> values(c + 1);

    int edges = -1;

    while(!pq.empty()){
        int weight = pq.top().first;
        int k = pq.top().second;
        pq.pop();
        if(searched[k]) continue;
        values[k] = max(values[k], weight);
        searched[k] = 1;
        edges++;
        if(edges == c - 1) break;
        for(int i : paths[k]){
            if(!searched[i]){
                pq.emplace(weights[k][i], i);
            }
        }
    }

    int m = INT32_MAX;
    for(int i : dest){
        cout << values[i] << "\n";
        m = min(values[i], m);
    }

    cout << m << "\n";
}

int main(void){
    solve();
    return 0;
}