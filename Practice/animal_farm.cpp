/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>

using namespace std;
using ll = long long;

vector<vector<int>> nodes(101);
vector<vector<int>> nvalues(101, vector<int>(101));
vector<vector<int>> values(1001, vector<int>(1001));
vector<pair<int, int>> edges;
vector<vector<vector<int>>> connected(1001, vector<vector<int>>(1001));

int prims(int m){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> searched(m);
    pq.emplace(0, 0);
    int num = 0;
    int total = 0;
    while(!pq.empty()){
        if(num >= m) break;
        int v = pq.top().first;
        int index = pq.top().second;
        if(index >= m) continue;
        pq.pop();
        if(searched[index]) continue;
        total += v;
        searched[index] = true;
        num++;
        for(int i : nodes[index]){
            if(searched[i]) continue;
            if(i >= m) continue;
            pq.emplace(nvalues[index][i], i);
        }
    }
    if(num < m) return 999999999;
    return total;
}

void solve(){
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int e;
        cin >> e;
        vector<int> edge(e + 1);
        vector<int> value(e);
        for(int j = 0; j < e; j++){
            cin >> edge[j];
        }
        for(int j = 0; j < e; j++){
            cin >> value[j];
        }
        edge[e] = edge[0];
        for(int j = 0; j < e; j++){
            int c1 = edge[j];
            int c2 = edge[j + 1];
            connected[c1][c2].push_back(i);
            connected[c2][c1].push_back(i);
            values[c1][c2] = value[j];
            values[c2][c1] = value[j];
            edges.emplace_back(c1, c2);
        }
    }

    for(pair<int, int> e : edges){
        for(int i : connected[e.first][e.second]){
            for(int j : connected[e.first][e.second]){
                if(i == j) continue;
                if(nvalues[i][j] == 0){
                    nodes[i].push_back(j);
                    nodes[j].push_back(i);
                    nvalues[i][j] = values[e.first][e.second];
                    nvalues[j][i] = values[e.first][e.second];
                }else{

                    nvalues[i][j] = min(nvalues[i][j], values[e.first][e.second]);
                    nvalues[j][i] = min(nvalues[j][i], values[e.first][e.second]);
                }
            }
        }
        if(connected[e.first][e.second].size() == 1){
            int i = connected[e.first][e.second][0];
            if(nvalues[i][m] == 0){
                nodes[i].push_back(m);
                nodes[m].push_back(i);
                nvalues[i][m] = values[e.first][e.second];
                nvalues[m][i] = values[e.first][e.second];
            }else{
                nvalues[i][m] = min(nvalues[i][m], values[e.first][e.second]);
                nvalues[m][i] = min(nvalues[m][i], values[e.first][e.second]);
            }
        }
    }
    
    cout << min(prims(m), prims(m + 1)) << "\n";
}

int main(void){
    solve();
    return 0;
}