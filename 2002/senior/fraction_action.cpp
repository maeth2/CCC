/*

*/
#include <iostream>

using namespace std;
using ll = long long;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void solve(){
    int n, d, c = 0;
    cin >> n >> d;

    c = n;

    n /= gcd(n, d);
    d /= gcd(c, d);

    if(n > d) cout << n / d;
    if(n % d > 0) cout << (n > d ? " " : "") << n % d << "/" << d;
    cout << "\n";
}

int main(void){
    solve();
    return 0;
}