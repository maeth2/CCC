/*
The Enemy relies heavily on the transportation of supplies and personnel between the
specific points A and B. Points A and B, as well as other points C, D, E, etc. are linked by
a network of roads. Your mission, should you accept it, is to identify a single road that
may be bombed in order to cut off all traffic between A and B.
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

bool find_path(int a, int b, vector<int> connected[26]){
    queue<int> pq;
    int searched[26];
    for(int i = 0; i < 26; i++) searched[i] = 0;
    pq.push(0);
    while(!pq.empty()){
        int c = pq.front();
        pq.pop();
        searched[c] = 1;
        if(c == 1) return 1;
        for(int i : connected[c]){
            if((c == a && i == b) || (c == b && i == a) || searched[i]) continue;
            pq.push(i);
        }
    }
    return 0;
}
void solve(){

    int total = 0;

    string c;
    cin >> c;

    vector<string> edges;
    vector<int> connected[26];
    
    while(c != "**"){
        int a = c[0] - 'A';
        int b = c[1] - 'A';
        connected[a].push_back(b);
        connected[b].push_back(a);
        edges.push_back(c);
        cin >> c;
    }

    for(string i : edges){
        if(!find_path(i[0] - 'A', i[1] - 'A', connected)){
            cout << i << "\n";
            total++;
        }
    }

    cout << "There are " << total << " disconnecting roads.\n";
}

int main(void){
    solve();
    return 0;
}