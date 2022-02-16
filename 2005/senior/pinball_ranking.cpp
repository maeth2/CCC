/*

*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
using ll = long long;

void split(vector<ll> a, vector<ll> &b, ll start, ll end){
    for(ll i = start; i < end; i++){
        b.push_back(a[i]);
    }
}

void print(vector<ll> a){
    for(ll i : a){
        cout << i << ' ';
    }
    cout << '\n';
}

ll sort(vector<ll> &a, ll num, ll i){
    ll index = 0;
    ll middle = a.size() % 2 == 1 ? (a.size() + 1) / 2 : a.size() / 2;
    vector<ll> left, right;

    if(a.size() == 1){
        if(num < a[0]){
            a.push_back(num);
            return i + 1;
        }else if(num >= a[0]){
            a.insert(a.begin(), num);
            return i;
        }
    }else{
        if(a.size() % 2 == 1){
            split(a, left, 0, middle);
            split(a, right, middle, a.size());
        }else{
            split(a, left, 0, middle);
            split(a, right, middle, a.size());
        }

        // 1 2 2 2 2 2 3 3 3
        if(num > a[middle]){
            index = sort(left, num, i);
        }else if(num < a[middle]){
            index = sort(right, num, i + middle);
        }else if(num == a[middle]){
            a.insert(a.begin() + middle, num);
            int j = middle;
            while(a[j] == num){
                j--;
            }
            return i + j + 1;
        }

        left.insert(left.end(), right.begin(), right.end());
        a = left;
    }
    return index;
}
void solve(){
    ll n, num;
    cin >> n;
    vector<ll> scores;
    double total = 0;
    for(ll i = 0; i < n; i++){
        cin >> num;
        if(scores.size() > 0){
            ll j = sort(scores, num, 0) + 1;
            total += j;
        }else{
            scores.push_back(num);
            total++;
        }
    }
    cout << scores.size() << "\n";
    cout << fixed << setprecision(2) << total / n;
}

int main(void){
    solve();
    return 0;
}