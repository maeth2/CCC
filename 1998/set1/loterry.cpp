/*
You have just won the lottery. All that separates you from your multi-million dollar prize is
your correct answer to the following skill-testing question:
1234 + 4567 X 11
In your twenty seconds you see your fortune slipping away because you don't know
whether the answer is
(1234 + 4567) X 11 = 63811
or
1234 + (4567 X 11) = 51471.
Finally you guess 63811, but that answer is incorrect. Your math teacher set the question
and expected you to remember that multiplication is done before addition. The correct
answer is 51471.
Your job is to write a program to insert parentheses into lottery questions such as the above
so as to make clear the order of operations.
The input to your program consists of a line containing an integer, n, followed by n lines of
input. Each of the n lines contains an expression consisting of integers, and the operators +,
–, and X (upper case X) denoting addition, subtraction and multiplication respectively.
Adjacent integers are separated by one operator. There is a single space to the left and to the
right of each operator and no input line contains more than 80 characters.
Your output should consist of the same n lines, with a blank line between them, with
parentheses inserted in the n lines so as to indicate the order of operations. Multiplication
should be done first, from right to left, and addition and subtraction should then be done
from left to right. Spaces surrounding operators should be preserved.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int solve(){
    string equation;
    getline(cin, equation);
    string number;
    vector<string> numbers;

    for(int i = 0; i < equation.size(); i++){
        string e(1, equation[i]);
        if(e == "X" || e == "+" || e == "-"){
            numbers.push_back(number);
            numbers.push_back(e);
            number.clear();
            continue;
        }
        if(equation[i] != ' '){
            number.push_back(equation[i]);
        }
    }

    numbers.push_back(number);

    bool found = true;
    while(found){
        found = false;
        for(int i  = 0; i < numbers.size(); i++){
            if(numbers[i] == "X"){
                string bracket;
                bracket = "(" + numbers[i-1] + " " + numbers[i] + " " + numbers[i+1] + ")";
                numbers.erase(numbers.begin() + (i - 1));
                numbers.erase(numbers.begin() + (i - 1));
                numbers.erase(numbers.begin() + (i - 1));
                numbers.insert(numbers.begin() + (i - 1), bracket);
                found = true;
                break;
            }
        }
    }

    found = true;
    while(found){
        found = false;
        for(int i  = 0; i < numbers.size(); i++){
            if(numbers[i] == "+" && numbers.size() > 3){
                string bracket;
                bracket = "(" + numbers[i-1] + " " + numbers[i] + " " + numbers[i+1] + ")";
                numbers.erase(numbers.begin() + (i - 1));
                numbers.erase(numbers.begin() + (i - 1));
                numbers.erase(numbers.begin() + (i - 1));
                numbers.insert(numbers.begin() + (i - 1), bracket);
                found = true;
                break;
            }
        }
    }

    for(int i = 0; i < numbers.size(); i++){
        cout << numbers[i] << " ";
    }
    cout << "\n";
}

int main(void){
    int t;
    string none;
    cin >> t;
    getline(cin, none);

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}