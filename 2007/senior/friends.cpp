/*

*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Relationships{
    int i, fi, num, fnum;
};

vector<Relationships> relationships;

int to_index(int i){
    for(Relationships r : relationships){
        if(i == r.num){
            return r.i;
        }
    }
    return -1;
}

int check_layer(int a, int b, int layer, vector<bool> searched){
    searched[a] = true;
    if(a == b) return layer - 1;
    if(searched[relationships[a].fi]) return -1;
    return check_layer(relationships[a].fi, b, layer + 1, searched);
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int sn, fn;
        cin >> sn >> fn;
        Relationships r = {i, -1, sn, fn};
        relationships.push_back(r);
    }
    
    for(Relationships &r : relationships){
        r.fi = to_index(r.fnum);
    }

    while(true){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        a = to_index(a);
        b = to_index(b);
        vector<bool> searched(n);
        int layer = check_layer(a, b, 0, searched);
        if(layer == -1){
            cout << "No\n";
        }else{
            cout << "Yes " << layer << "\n";
        }
    }
}

int main(void){
    solve();
    return 0;
}