/*

*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int max(int a, int b){return a > b ? a : b;}
bool u[4];

int recurse(int hand[], int i, vector<int> stack, bool used[]){
    int mx = -1;

    if(i < 4){
        for(int j = 0; j < 4; j++){
            if(!used[j]){
                used[j] = true;
                vector<int> ns = stack;
                ns.push_back(hand[j]);
                mx = max(mx, recurse(hand, i + 1, ns, used));
                used[j] = false;
            }
        }
    }

    if(stack.size() == 1 && i == 4){
        return stack[0] > 24 ? 0 : stack[0];
    }

    if(stack.size() >= 2){
        int a = stack[stack.size() - 1];
        int b = stack[stack.size() - 2];
        
        vector<int> ns = stack;
        ns.pop_back();
        ns[ns.size() - 1] = a + b;
        mx = max(mx, recurse(hand, i, ns, used));

        ns = stack;
        ns.pop_back();
        ns[ns.size() - 1] = a - b;
        mx = max(mx, recurse(hand, i, ns, used));

        ns = stack;
        ns.pop_back();
        ns[ns.size() - 1] = a * b;
        mx = max(mx, recurse(hand, i, ns, used));

        if(b != 0 && a % b == 0){
            ns = stack;
            ns.pop_back();
            ns[ns.size() - 1] = a / b;
            mx = max(mx, recurse(hand, i, ns, used));
        }
    }
 
    return mx;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < 4; i++){
        u[i] = false;
    }
    for(int i = 0; i < n; i++){
        int hand[4];
        cin >> hand[0] >> hand[1] >> hand[2] >> hand[3];
        vector<int> stack;
        int ans = recurse(hand, 0, stack, u);
        cout << ans << '\n';
    }
}

int main(void){
    solve();
    return 0;
}