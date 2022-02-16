/*
Kruskal's algorithm
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int parent[10001];
int dest[10001];

int root(int a){
    if(a != parent[a]){
        parent[a] = root(parent[a]);
    }
    return parent[a];
}

void merge(int a, int b){
    int p = root(a);
    int q = root(b);
    parent[p] = q;
}

void solve(){
    int c, r, d;
    cin >> c >> r >> d;
    vector<pair<int, pair<int, int>>> edges;

    for(int i = 0; i < r; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }

    for(int i = 0; i < d; i++){
        int a;
        cin >> a;
        dest[a] = 1;
    }

    sort(edges.begin(), edges.end(), greater<>());

    for(int i = 1; i <= c; i++){
        parent[i] = i;
    }

    int visited = 0;

    for(auto &e : edges){
        int a = e.second.first;
        int b = e.second.second;
        if(root(a) != root(b)){
            if(dest[a]){
                dest[a] = 0;
                visited++;
            }
            if(dest[b]){
                dest[b] = 0;
                visited++;
            }
            if(visited == d){
                cout << e.first;
                break;
            }
            merge(a, b);
        }
    }
}

int main(void){
    solve();
    return 0;
}