/*

*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve(){
    vector<char> order = {'A', 'B', 'C', 'D', 'E'};
    while(true){
        int b, n;
        cin >> b >> n;
        for(int i = 0; i < n; i++){
            if(b == 1){
                order.push_back(order[0]);
                order.erase(order.begin());                
            }else if(b == 2){
                order.insert(order.begin(), order[4]);
                order.erase(order.begin() + order.size() - 1);
            }else if(b == 3){
                char a0, a1;
                a0 = order[0];
                a1 = order[1];
                order[1] = a0;
                order[0] = a1;
            }
        }
        if(b == 4) break;
    }
    for(char i : order){
        cout << i << ' ';
    }
    cout << "\n";
}

int main(void){
    solve();
    return 0;
}