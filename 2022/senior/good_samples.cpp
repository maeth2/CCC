/*

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

ll min(ll a, ll b){return a > b ? b : a;}

void solve(){
    ll n,m,k; 
    cin>>n>>m>>k;
    vector<ll> ans; 
    for(ll i=0;i<n;i++)
    {   
        ll rem = n-i-1;
        ll cur = min(k-rem, m);
        if(cur<=0) break;  
        ll val;
        if(cur > i)//Add distinctive number
        {   
            val= min(m, i + 1);
            cur=val; 
        }
        else{ //Add non-distinctive number
            val=ans[i-cur]; 
        }
        ans.push_back(val);
        k = k - cur;
    }
    if(k==0 and (ll)ans.size()==n)
    {
        for(auto x: ans) cout<<x<<' '; 
        cout<<endl; 
    }
    else cout<<-1<<endl;
}

int main(void){
    solve();
    return 0;
}