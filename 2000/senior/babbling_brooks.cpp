/*
A series of streams run down the side of a mountain. The mountainside is very rocky so
the streams split and rejoin many times. At the foot of the mountain, several streams
emerge as rivers. Your job is to compute how much water flows in each river.

At any given elevation there are n streams, labelled 1 to n from left-to-right. As we
proceed down the mountainside, one of the streams may split into a left fork and a right
fork, increasing the total number of streams by 1, or two streams may rejoin, reducing the
total number of streams by 1. After a split or a rejoining occurs, the streams are
renumbered consecutively from left-to-right. There is always at least one stream and
there are never more than 100 streams
*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int solve(){
    float n;
    cin >> n;
    vector<float> streams(n);
    for(int i = 0; i < n; i++){
        cin >> streams[i];
    }
    int a = 0;
    while(a != 77){
        cin >> a;
        if(a == 99){
            int i;
            float j;
            cin >> i >> j;
            j *= 0.01;
            float flow = streams[i - 1];
            streams[i - 1] = flow * j;
            streams.insert(streams.begin() + i, flow * (1 - j));
        }else if(a == 88){
            int i;
            cin >> i;
            streams[i - 1] += streams[i];
            streams.erase(streams.begin() + i); 
        }
    }

    for(int i = 0; i < streams.size(); i++){
        cout << streams[i] << " ";
    }
}

int main(void){
    solve();

    return 0;
}