/*
There is an ancient saying that "All Roads Lead to Rome". If this were true, 
then there is a simple algorithm for finding a path between any two cities. 
To go from city A to city B, a traveller could take a road from A to Rome, then 
from Rome to B. Of course, a shorter route may exist.

The network of roads in the Roman Empire had a simple structure: beginning at 
Rome, a number of roads extended to the nearby cities. From these cities, more 
roads extended to the next further cities, and so on. Thus, the cities could be 
thought of as existing in levels around Rome, with cities in the ith level only 
connected to cities in the i-1st and i+1st levels (Rome was considered to be at level 0). 
No loops existed in the road network. Any city in level i was connected to a single city 
in level i-1, but was connected to zero or more cities in level i+1. Thus, to get to Rome 
from a given city in level i, a traveller could simply walk along the single road leading 
to the connected i-1 level city, and repeat this process, with each step getting closer to 
Rome.

Given a network of roads and cities, your task is to find the shortest route between any 
two given cities, where distance is measured in the number of intervening cities.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

pair<int, string> dfs(char c, vector<vector<char>> path, int searched[26], char e, int l, string pt){
    pair<int, string> p = make_pair(INT8_MAX, "*");

    string t = pt + c;

    if(c == e){
        return make_pair(l, pt + e);
    }

    for(int i = 0; i < path[c - 'A'].size(); i++){
        char a = path[c - 'A'][i];
        if(!searched[a - 'A']){
            searched[a - 'A'] = 1;
            pair<int, string> p1 = dfs(path[c - 'A'][i], path, searched, e, l + 1, t);
            if(p1.first < p.first){
                p = p1;
            }
            searched[a - 'A'] = 0;
        }
    }

    return p;
}

int solve(){
    int m, n;

    cin >> m >> n;

    vector<vector<char>> path(26); 

    vector<pair<char, char>> query;

    for(int i = 0; i < m; i++){
        string city1, city2;
        cin >> city1 >> city2;
        path[city1[0] - 'A'].push_back(city2[0]);
        path[city2[0] - 'A'].push_back(city1[0]);
    }

    for(int i = 0; i < n; i++){
        string city1, city2;
        cin >> city1 >> city2;
        query.emplace_back(city1[0], city2[0]);
    }

    int searched[26];
    for(int i = 0; i < 26; i++) searched[i] = 0;

    for(int i = 0; i < query.size(); i++) cout << dfs(query[i].first, path, searched, query[i].second, 0, "").second << "\n";
}

int main(){
    solve();
    return 0;
}