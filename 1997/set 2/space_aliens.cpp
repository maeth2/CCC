/*
Earth is being attacked by space aliens yet again. The invasion is being tracked by time-lapse photography. 
Three photographs have been taken at equal time intervals. Your job is to predict the positions of the alien 
craft in the next photograph, so that they may be intercepted by Earth's defence force. Each alien craft 
appears as a point of light in the plane of the photograph.

Your input consists of three snapshots of the crafts' positions, taken at 1/10 second intervals. During 
these intervals, each craft's speed and direction may be assumed to be constant. Your output consists of 
the coordinates at which the craft will appear 1/10 second after the third snapshot. (ie The positions in 
the fourth snapshot if there were one.)
*/
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
using ll = long long;

bool check_tuple(tuple<int, int, int, float, float> v1, tuple<int, int, int, float, float> v2){
    int a, b, c, a1, b1, c1;

    a = get<0>(v1);
    b = get<1>(v1);
    c = get<2>(v1);
    
    a1 = get<0>(v2);
    b1 = get<1>(v2);
    c1 = get<2>(v2);

    if(a1 == a || b1 == b || c1 == c) return true;

    return false;
}
int solve(){
    int n;
    cin >> n;

    vector<vector<pair<float, float>>> a(3);
    vector<vector<vector<pair<float, float>>>> b(2, vector<vector<pair<float, float>>>(n, vector<pair<float, float>>(n)));
    vector<tuple<int, int, int, float, float>> c;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            float x, y;
            cin >> x >> y;
            a[i].emplace_back(x, y);
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                pair<float, float> m;
                m.first =  (a[i][j].first - a[i + 1][k].first) * -1;
                m.second = (a[i][j].second - a[i + 1][k].second) * -1;
                b[i][j][k] = m;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(b[0][i][j] == b[1][j][k]){
                    c.emplace_back(i, j, k, b[0][i][j].first, b[0][i][j].second);
                }
            }
        }
    }

    vector<vector<tuple<int, int, int, float, float>>> possible_paths;
    vector<int> searched(c.size());
    vector<tuple<int, int, int, float, float>> v;

    for(int i = 0; i < c.size(); i++){
        if(!searched[i]){
            bool found = false;
            int f, s, t;
            f = get<0>(c[i]);
            s = get<1>(c[i]);
            t = get<2>(c[i]);
        }
        if(v.size() == n){
            possible_paths.push_back(v);
            v.clear();
        }
    }

    for(int i = 0; i < c.size(); i++){
        for(int j = i; j < c.size(); j++){
            for(int k = j; k < c.size(); k++){
                if(!check_tuple(c[i], c[j]) && !check_tuple(c[i], c[k]) && ! check_tuple(c[j], c[k])){
                    v.push_back(c[i]);
                    v.push_back(c[j]);
                    v.push_back(c[k]);
                    possible_paths.push_back(v);
                    v.clear();
                }
            }
        }
    }

    cout << "\n" << n << "\n";
    
    for(int i = 0; i < possible_paths.size(); i++){
        for(int j = 0; j < possible_paths[i].size(); j++){
            pair<float, float> pos;
            float x, y;
            pos = a[2][get<2>(possible_paths[i][j])];
            x = get<3>(possible_paths[i][j]);
            y = get<4>(possible_paths[i][j]);
            cout << pos.first + x << " " << pos.second + y << "\n";
        }
        cout << "\n";
    }
}

int main(void){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}