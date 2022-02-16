/*

*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

vector<vector<int>> net(19);

void add_new(int x){
    if(x > net.size() - 1){
        int j = x - (net.size() - 1);
        for(int i = 0; i < j; i++){
            vector<int> a;
            net.push_back(a);
        }
    }
}

bool check_connection(int x, int y){
    bool found = false;
    for(int i : net[x]){
        if(i == y){
            found = true;
            break;
        }
    }
    return found;
}

int friends_of_friends(int x){
    vector<bool> searched(net.size());
    int a = 0;
    searched[x] = true;
    for(int i : net[x]){
        searched[i] = true;
    }
    for(int i : net[x]){
        for(int j : net[i]){
            if(searched[j]) continue;
            searched[j] = true;
            a++;
        }
    }
    return a;
}

int find_degree(int x, int y){
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>> > pq;
    vector<bool> searched(net.size());
    pq.emplace(0, x);
    while(!pq.empty()){
        int d = pq.top().first;
        int c = pq.top().second;
        if(c == y){
            return d;
        }

        searched[c] = true;
        pq.pop();

        for(int i : net[c]){
            if(searched[i]) continue;
            pq.emplace(d + 1, i);
        }
    }
    return -1;
}

void solve(){
    net[1].push_back(6);

    net[2].push_back(6);

    net[3].push_back(4);
    net[3].push_back(5);
    net[3].push_back(6);
    net[3].push_back(15);

    net[4].push_back(3);
    net[4].push_back(5);
    net[4].push_back(6);

    net[5].push_back(3);
    net[5].push_back(4);
    net[5].push_back(6);

    net[6].push_back(1);
    net[6].push_back(2);
    net[6].push_back(3);
    net[6].push_back(4);
    net[6].push_back(5);
    net[6].push_back(7);

    net[7].push_back(6);
    net[7].push_back(8);

    net[8].push_back(7);
    net[8].push_back(9);

    net[9].push_back(8);
    net[9].push_back(10);
    net[9].push_back(12);

    net[10].push_back(9);
    net[10].push_back(11);

    net[11].push_back(10);
    net[11].push_back(12);

    net[12].push_back(9);
    net[12].push_back(11);
    net[12].push_back(13);

    net[13].push_back(12);
    net[13].push_back(14);
    net[13].push_back(15);

    net[14].push_back(13);

    net[15].push_back(3);
    net[15].push_back(13);

    net[16].push_back(17);
    net[16].push_back(18);

    net[17].push_back(16);
    net[17].push_back(18);

    net[18].push_back(16);
    net[18].push_back(17);

    char c = ' ';
    int x, y;
    while(c != 'q'){
        cin >> c;
        if(c == 'q') break;
        if(c == 'i'){
            cin >> x >> y;
            add_new(x);
            add_new(y);
            if(!check_connection(x, y)){
                net[x].push_back(y);
                net[y].push_back(x);
            }
        }else if(c == 'd'){
            cin >> x >> y;
            if(check_connection(x, y)){
                net[x].erase(find(net[x].begin(), net[x].end(), y));
                net[y].erase(find(net[y].begin(), net[y].end(), x));
            }
        }else if(c == 'n'){
            cin >> x;
            cout << net[x].size() << "\n";
        }else if(c == 'f'){
            cin >> x;            
            cout << friends_of_friends(x) << "\n";
        }else if(c == 's'){
            cin >> x >> y;
            int degree = find_degree(x, y);
            if(degree == -1) cout << "Not connected\n";
            else cout << degree << "\n";
        }
    }
}

int main(void){
    solve();
    return 0;
}