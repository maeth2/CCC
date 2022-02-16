/*

*/
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int max(int a, int b){return a > b ? a : b;}
int min(int a, int b){return a < b ? a : b;}

void print_vector(vector<vector<int>> tensor){
    for(int i = 0; i < tensor.size(); i++){
        for(int j = 0 ; j < tensor[0].size(); j++){
            cout << tensor[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n";
}

vector<vector<int>> tensor_product(vector<vector<int>> a, vector<vector<int>> b){
    int r1, r2, c1, c2;
    r1 = a.size();
    c1 = a[0].size();
    r2 = b.size();
    c2 = b[0].size();

    vector<vector<int>> tensor(r1 * r2, vector<int>(c1 * c2));

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            for(int i1 = 0; i1 < r2; i1++){
                for(int j1 = 0; j1 < c2; j1++){
                    tensor[i * r2 + i1][j * c2 + j1] = a[i][j] * b[i1][j1];
                }
            }
        }
    }
    
    return tensor;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<vector<int>>> matrices;

    while(n > 0){
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> matrix[i][j];
            }
        }
        matrices.push_back(matrix);
        n--;
    }
    
    vector<vector<int>> tensor = tensor_product(matrices[0], matrices[1]);

    for(int i = 2; i < matrices.size(); i++){
        tensor = tensor_product(tensor, matrices[i]);
    }

    int emax = INT32_MIN, emin = INT32_MAX, rmax = INT32_MIN, rmin = INT32_MAX, cmax = INT32_MIN, cmin = INT32_MAX;

    for(int i = 0; i < tensor.size(); i++){
        int total = 0;
        for(int j = 0; j < tensor[0].size(); j++){
            emax = max(emax, tensor[i][j]);
            emin = min(emin, tensor[i][j]);
            total += tensor[i][j];
        }
        rmax = max(rmax, total);
        rmin = min(rmin, total);
    }

    for(int i = 0; i < tensor[0].size(); i++){
        int total = 0;
        for(int j = 0; j < tensor.size(); j++){
            total += tensor[j][i];
        }
        cmax = max(cmax, total);
        cmin = min(cmin, total);
    }

    cout << emax << '\n' << emin << '\n';
    cout << rmax << '\n' << rmin << '\n';
    cout << cmax << '\n' << cmin << '\n';

}

int main(void){
    solve();
    return 0;
}