/*

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

vector<int> houses;
int street = 1000000;
int h, k;

bool min_hydrants(int length) {
    int n = houses.size();
	for (int i = 0; i < n; i++) {
		int count = 0; int countK = 0; int index = i;
		while (count != n) {
			int current = houses[index];
			count++; countK++; index++; index=index%n;
            int cl = current + length + length;
			while (count < n && cl % street >= houses[index]) {
				if (cl < street) {
					if(houses[index] < current){
                        cout << current << ' ' << houses[index] << ' ' << cl % street << '\n';
                        break;
                    }
				}
                count++; index++; index=index%n;
			}
		}
		if (countK <= k) {return true;}
	}
	return false;
}

void solve() {
    cin >> h;
    for(int i = 0; i < h; i++) {
        int a;
        cin >> a;
        houses.push_back(a);
    }
    cin >> k;
    if(k >= h) {
        cout << 0 << '\n';
        return;
    }
    sort(houses.begin(), houses.end());
    for(int i : houses){
        cout << i << '\n';
    }
    //Binary Search
    int high = street;
    int low = 0;
    int mid = (low + high) / 2;
    while(high - low > 2){
        if(min_hydrants(mid)){
            high = mid;
        }else{
            low = mid;
        }
        mid = (low + high) / 2;
    }
    while(min_hydrants(mid)){
        mid--;
    }
    cout << mid + 1 << '\n';
}

int main(void){
    solve();
    return 0;
}