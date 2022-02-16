/*

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int LCP(string a, string b){
    int n = a.size() > b.size() ? b.size() : a.size();
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) return i;
    }
    return n;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string c;
        int total = 0;
        cin >> c;
        vector<string> suffix;

        for(int j = 0; j < c.size(); j++){
            suffix.push_back(c.substr(j, c.size() - j));
        }

        for(int j = 0; j < suffix.size() - 1; j++){
            for(int k = j + 1; k < suffix.size(); k++){
                int min = suffix[j].size() < suffix[k].size() ? suffix[j].size() : suffix[k].size();
                for(int z = 0; z < min; z++){
                    if(suffix[j][z] - 'A' == suffix[k][z] - 'A'){
                        if(z == min - 1){
                            if(suffix[j].size() > suffix[k].size()) swap(suffix[j], suffix[k]);
                        }else continue;
                    }else if(suffix[j][z] - 'A' > suffix[k][z] - 'A'){
                        swap(suffix[j], suffix[k]);
                    }
                    break;
                }
            }
        }

        int count = suffix[0].size() + 1;
        for(int j = 1; j < c.size(); j++){
            int lcp = LCP(suffix[j], suffix[j - 1]);
            count = count + suffix[j].size() - lcp;
        }
        cout << count << "\n";
    }
}

int main(void){
    solve();
    return 0;
}