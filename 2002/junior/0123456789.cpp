/*

*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    
    if(n == 0){
        cout << " * * *\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << "\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << " * * *\n";
    }else if(n == 1){
        cout << "\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "\n";
    }else if(n == 2){
        cout << " * * *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << " * * *\n";
        cout << "*\n";
        cout << "*\n";
        cout << "*\n";
        cout << " * * *\n";
    }else if(n == 3){
        cout << " * * *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << " * * *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << " * * *\n";
    }else if(n == 4){
        cout << "\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << " * * *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "\n";
    }else if(n == 5){
        cout << " * * *\n";
        cout << "*\n";
        cout << "*\n";
        cout << "*\n";
        cout << " * * *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << " * * *\n";
    }else if(n == 6){
        cout << " * * *\n";
        cout << "*\n";
        cout << "*\n";
        cout << "*\n";
        cout << " * * *\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << " * * *\n";
    }else if(n == 7){
        cout << " * * *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "\n";
    }else if(n == 8){
        cout << " * * *\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << " * * *\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << " * * *\n";
    }else if(n == 9){
        cout << " * * *\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << "*     *\n";
        cout << " * * *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << "      *\n";
        cout << " * * *\n";
    }
}

int main(void){
    solve();
    return 0;
}