/*

*/

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void solve(){
    int n, k;
    int points[100];
    int place[100];
    int worst[100];
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        place[i] = i;
        points[i] = 0;
        worst[i] = 0;
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            int score;
            cin >> score;
            points[j] += score;
        }

        for(int j = 0; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(points[place[j]] < points[place[k]]){
                    swap(place[j], place[k]);
                }
            }
        }

        int p = 0;
        int cp = points[place[0]];
        for(int i = 0; i < n; i++){
            if(points[place[i]] < cp) p++;
            if(worst[place[i]] < p) worst[place[i]] = p;
        }
    }
    int first = points[place[0]];
    for(int i = 0; i < n; i++){
        if(points[i] == first) cout << "Yodeller " << i + 1 << " is the TopYodeller: score " << points[i] << ", worst rank " << worst[i] + 1 << "\n";
    }

}

int main(void){
    solve();
    return 0;
}