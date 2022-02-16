/*
Given a sequence of m words from a newspaper article and an integer k, find the kth most common word.
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

int solve(){
    int m, k;
    cin >> m >> k;
    
    map<string, int> dict;

    for(int i = 0; i < m; i++){
        string word;
        cin >> word;
        if(dict.find(word) != dict.end()){
            dict.find(word) -> second += 1;
        }else{
            dict.insert(pair<string, int>(word, 1));
        }
    }
    
    vector<string> rank;
    vector<int> v;

    for(auto it = dict.cbegin(); it != dict.cend(); ++it){
        rank.emplace_back(it->first);
        v.emplace_back(it->second);
    }

    bool swapped = true;

    while(swapped && m > 0){        
        swapped = false;
        for(int i = 0; i < rank.size() - 1; i++){
            if(v[i] < v[i + 1]){
                swap(v[i], v[i + 1]);
                swap(rank[i], rank[i + 1]);
                swapped = true;
            }
        }
    }

    for(int i = 0; i < rank.size(); i++){
        cout << rank[i] << " " << v[i] << "\n";
    }
    int prev = -1;
    int z = 0;
    cout << k << (k == 1 ? " st" : k == 2 ? " nd" : k == 3 ? " rd" : " th") << " most common word: \n";
    for(int i = 0; i < rank.size(); i++){
        if(v[i] != prev){
            prev = v[i];
            z++;
        }
        if(z == k){
            cout << rank[i] << "\n";
        }
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