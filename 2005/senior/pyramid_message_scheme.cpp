/*

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int max(int a, int b) {return a > b ? a : b;}

int getIndex(string name, vector<string> &a, vector<vector<int>> &b){
    int index = -1;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == name){
            index = i;
            break;
        }
    }
    if(index == -1){
        index = a.size();
        b.emplace_back();
        a.push_back(name);
    }
    return index;
}

int hasConnection(int a, int b, vector<vector<int>> &c){
    for(int i = 0; i < c[a].size(); i++){
        if(c[a][i] == b){
            return 1;
        }
    }
    return 0;
}

int recurse(int index, int prevIndex, vector<vector<int>> c){
    int total = 0;
    for(int i : c[index]){
        if(i == prevIndex) continue;
        total = max(total, recurse(i, index, c));
    }
    return total + 1;
}

void solve(){
    int n, m;
    cin >> n;
    while(n){
        string name;
        vector<vector<int>> connections;
        vector<string> names;
        cin >> m;
        int prevIndex = -1;

        int index;
        for(int i = 0; i < m; i++){
            cin >> name;
            index = getIndex(name, names, connections);
            if(prevIndex != -1){
                if(!hasConnection(prevIndex, index, connections)){
                    connections[prevIndex].push_back(index);
                    connections[index].push_back(prevIndex);
                }
            }
            prevIndex = index;
        }

        cout << m * 10 - (recurse(index, -1, connections) - 1) * 20 << "\n";
        n--;
    }
}

int main(void){
    solve();
    return 0;
}