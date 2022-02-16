/*

*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
using ll = long long;

double I = 0;

double merge(vector<int> &a, int x, int y, int z){
    vector<int> newa (z - x + 1);
	int xx = x;
	int yy = y + 1;
	int k = 0;
	double total = 0;
	while (xx <= y && yy <= z){
	    if (a [xx] <= a [yy]){
		    newa [k++] = a [xx++];
        }else{
            newa [k++] = a [yy++];
            total = total + (y + 1 - xx);
	    }
    }
	while (xx <= y)
	    newa [k++] = a [xx++];
	while (yy <= z)
	    newa [k++] = a [yy++];
	for (xx = x ; xx <= z ; xx++)
	    a [xx] = newa [xx - x];
	return total;
}

void mergeSort(vector<int> &a, int x, int z){
	if (x < z)
	{
	    int y = (x + z) / 2;
	    mergeSort (a, x, y);
	    mergeSort (a, y + 1, z);
	    I += merge (a, x, y, z);
	}
}

void solve(){
    int n, num;
    cin >> n;
    vector<int> scores;
    for(int i = 0; i < n; i++){
        cin >> num;
        scores.push_back(num);
    }
    mergeSort(scores, 0, n - 1);
    cout << fixed << setprecision(2) << (I + n) / n;
}

int main(void){
    solve();
    return 0;
}