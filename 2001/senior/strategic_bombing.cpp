/*
The Enemy relies heavily on the transportation of supplies and personnel between the
specific points A and B. Points A and B, as well as other points C, D, E, etc. are linked by
a network of roads. Your mission, should you accept it, is to identify a single road that
may be bombed in order to cut off all traffic between A and B.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void dfs (int a, int d, vector<int> searched, vector<vector<int>> paths, vector<string> &connections, string path){
    searched[a] = 1;
    path.push_back(a + 'A');
    if(a == d){
        connections.push_back(path);
        return;
    }
    for(int i = 0; i < paths[a].size(); i++){
        if(!searched[paths[a][i]]){
           dfs(paths[a][i], d, searched, paths, connections, path);
        }
    }
}

void solve(){
    vector<vector<int>> paths(26);
    vector<string> raw_path;
    string c;
    cin >> c;
    while(c != "**"){
        int a = c[0] - 'A';
        int b = c[1] - 'A';
        paths[a].push_back(b);
        paths[b].push_back(a);
        raw_path.push_back(c);
        cin >> c;
    }

    vector<int> searched(26);
    vector<string> connections;
    dfs(0, 1, searched, paths, connections, "");

    vector<vector<int>> connected_paths(26, vector<int>(26));
    for(int i = 0; i < connections.size(); i++){
        for(int j = 0; j < connections[i].size() - 1; j++){
            int a = connections[i][j] - 'A';
            int b = connections[i][j + 1] - 'A';
            connected_paths[a][b]++;
        }
    }

    int total = 0;

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(connected_paths[i][j] == connections.size()){
                char a = i + 'A';
                char b = j + 'A';
                for(int k = 0; k < raw_path.size(); k++){
                    if((raw_path[k][0] == a && raw_path[k][1] == b) || (raw_path[k][0] == b && raw_path[k][1] == a)){
                        cout << raw_path[k] << "\n";
                    }
                }
                total++;
            }
        }
    }
    cout << "There are " << total << " disconnecting roads.\n";
}

int main(void){
    solve();
    return 0;
}