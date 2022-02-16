/*

*/
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
using ll = long long;

struct Box{
    int l, w, h, a;
};

bool check_size(int l, int w, int h, Box b){
    return l <= b.l && w <= b.w && h <= b.h;
}

void sort(vector<Box> &b){
    for(int i = 0; i < b.size() - 1; i++){
        for(int j = 0; j < b.size() - i - 1; j++){
            if(b[j].a > b[j + 1].a){
                Box ta, tb;
                ta = b[j];
                tb = b[j + 1];
                b[j] = tb;
                b[j + 1] = ta;
            }
        }
    }
}

void solve(){
    int n;
    vector<Box> boxes;
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, w, h;
        cin >> l >> w >> h;
        Box b ={l, w, h, l * w * h};
        boxes.push_back(b);
    }
    
    sort(boxes);
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++){
        int dim[3];
        cin >> dim[0] >> dim[1] >> dim[2];
        bool fit = false;
        for(Box b : boxes){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(j == k) continue;
                    for(int z = 0; z < 3; z++){
                        if(z == k || z == j) continue;
                        if(check_size(dim[j], dim[k], dim[z], b)){
                            fit = true;
                            break;
                        }
                    }
                    if(fit) break;
                }
                if(fit) break;
            }
            if(fit){
                cout << b.a << "\n";
                break;
            }
        }
        if(!fit) cout << "Item does not fit.\n";
    }
}

int main(void){
    solve();
    return 0;
}