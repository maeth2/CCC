/*
Solve the following three problems. Solutions to the first two problems are to be generated
using a computer. The solution to the third problem may be done by hand, but must be
entered into the grid provided in the information/answer form.

1. Write a program to print the perfect numbers between 1000 and 9999 inclusive. A
perfect number is a positive integer which is equal to the sum of its proper divisors. A
proper divisor is any divisor less than the number itself. For example, 6 is a perfect
number since 1 + 2 + 3 = 6. The numbers should be printed one per line.

2. Write a program to generate all integers between 100 and 999 inclusive which are equal
to the sum of the cubes of their digits. The numbers are to be printed one per line.

3. Use the output from parts 1 and 2, and any other programs you care to write, to solve
the following cross-number puzzle.
*/
#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int solve(){
    for(int i = 1000; i < 10000; i++){
        int sum = 0;
        for(int j = 1; j < sqrt(i); j++){
            if(i % j == 0){
                sum += j;
                if(j != 1){
                    sum += i/j;
                }
            }
        }
        if(sum == i){
            cout << i << "\n";
        }
    }

    cout << "\n";
    
    for(int i = 100; i < 1000; i++){
        int sum = 0;
        int a = i;
        while(a > 0){
            int m = a % 10;
            sum += m * m * m;
            a -= m;
            a /= 10;
        }
        if(sum == i) cout << i << "\n";
    }
}

int main(void){
    solve();

    return 0;
}